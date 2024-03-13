#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{   
    int pid_test(void);
    int fork_test(void);

    int type = 1;
    switch (type)
    {
    case 0:
        pid_test();
        break;
    case 1:
        fork_test();
        break;
    default:
        break;
    }
}

int pid_test(void)
{
    pid_t pid;
    pid = getpid();
    printf("pid = %d\n", pid);
    pid_t pid_f;
    pid_f = fork();
    printf("pid_f = %d\n", pid_f);
    return 0;
}

int fork_test()
{
    pid_t pid;
    int x = 1;

    pid = fork();
    if (pid == 0) {
        printf("child: x=%d\n", ++x);
        return 0;
    }

    printf("parent: x=%d\n", --x);
    return 0;
}
