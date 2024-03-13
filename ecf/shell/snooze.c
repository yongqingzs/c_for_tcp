#include "../../csapp.h"
#define MAXARGS 128

void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);
void snooze_handler(int sig);

int main() {
    char cmdline[MAXLINE]; // Command line

    if (signal(SIGINT, snooze_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    while (1) {
        // Read
        printf("> ");
        fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin)) {
            exit(0);
        }

        // Evaluate
        eval(cmdline);
    }
}

void eval(char *cmdline) {
    char *argv[MAXARGS]; // Argument list
    char buf[MAXLINE]; // Holds modified command line
    int bg; // Should the job run in the background?

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL) {
        return; // Ignore empty lines
    }

    if (!builtin_command(argv)) {
        pid_t pid;
        if ((pid = fork()) == 0) { // Child runs user job
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

        // Parent waits for foreground job to terminate
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0) {
                printf("waitfg: waitpid error");
            }
        } else {
            printf("%d %s", pid, cmdline);
        }
    }
    return;
}

int parseline(char *buf, char **argv)
{
    char *delim; // Points to first space delimiter
    int argc; // Number of args
    int bg; // Background job?

    buf[strlen(buf)-1] = ' '; // Replace trailing '\n' with space
    while (*buf && (*buf == ' ')) { // Ignore leading spaces
        buf++;
    }

    // Build the argv list
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) { // Ignore spaces
            buf++;
        }
    }
    argv[argc] = NULL;

    if (argc == 0) { // Ignore blank line
        return 1;
    }

    // Should the job run in the background?
    if ((bg = (*argv[argc-1] == '&')) != 0) {
        argv[--argc] = NULL;
    }
    return bg;
}

void snooze_handler(int sig)
{
    printf("sig: %d\n", sig);
    exit(0);
}

unsigned int snooze(unsigned int secs) {
    unsigned int remaining = sleep(secs);
    if (remaining > 0) {
        printf("Remaining time: %u seconds\n", remaining);
    }
    return remaining;
}

int builtin_command(char **argv) {
    if (!strcmp(argv[0], "quit")) { // quit command
        exit(0);
    }
    if (!strcmp(argv[0], "&")) { // Ignore singleton &
        return 1;
    }
    if (!strcmp(argv[0], "snooze")) {
        snooze(atoi(argv[1]));
        return 1;
    }
    return 0; // Not a builtin command
}
