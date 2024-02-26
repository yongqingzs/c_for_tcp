#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#define N 2

int main()
{
    int status, i;
    pid_t pid[N], retpid;

    for (i = 0; i < N; i++)
        if ((pid[i] = fork()) == 0)
            exit(100 + i);

    i = 0;
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status=%d\n",
                    retpid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally\n", retpid);
    }

    if (errno != ECHILD)
        printf("waitpid error");

    exit(0);
}
