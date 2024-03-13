#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid, gpid;
    pid = getpid();
    gpid = getpgrp();
    printf("1pid = %d\n", pid);
    printf("1gpid = %d\n", gpid);
    printf("==========================\n");
    setpgid(pid, 114514);
    pid = getpid();
    gpid = getpgrp();
    printf("2pid = %d\n", pid);
    printf("2gpid = %d\n", gpid);
}