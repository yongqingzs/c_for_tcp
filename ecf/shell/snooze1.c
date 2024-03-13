#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void snooze_handler(int sig) {
    printf("\nInterrupted by SIGINT!\n");
}

unsigned int snooze(unsigned int secs) {
    unsigned int remaining = sleep(secs);
    if (remaining >= 0) {
        // printf("Remaining time: %u seconds\n", remaining);
        printf("Slept for %u of %u seconds.\n", secs - remaining, secs);
    }
    return remaining;
}

int main() {
    /* 
    只有这样，ctrl+c 才能中断 snooze 函数
     */
    // 设置 SIGINT 的处理函数为 snooze_handler
    if (signal(SIGINT, snooze_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    // 调用 snooze 函数
    snooze(5);

    return 0;
}