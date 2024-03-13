#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    if ((pid = fork()) == 0)
    {
        pause();
        printf("control should never reach here!\n");
        exit(0);
    }
    
    kill(pid, SIGKILL);  // 这里子进程已经被杀死了，但是父进程还在运行，上面的printf将失效
    exit(0);
}
