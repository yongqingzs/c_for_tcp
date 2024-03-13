#include "../../csapp.h"

void sigint_handler(int sig) {
    printf("\nCaught SIGINT!\n");
    exit(0);
}

int main(void)
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        unix_error("signal error");
    pause();  // 必须通过他接收信号
    exit(0);
}