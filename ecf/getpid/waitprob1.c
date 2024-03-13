#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int status;
    pid_t pid;

    printf("Hello\n");
    pid = fork();
    printf("%d\n", !pid);
    if (pid != 0)
    {
        if (waitpid(-1, &status, 0) > 0)
        {
            if (WIFEXITED(status))
                printf("child %d terminated normally with exit status=%d\n",
                       pid, WEXITSTATUS(status));
            else
                printf("child %d terminated abnormally\n", pid);
        }
    }
    printf("Bye\n");
    exit(2);
}
