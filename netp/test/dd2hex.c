#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    /* 将点分十进制转换为十六进制参数 */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dotted-decimal>\n", argv[0]);
        exit(1);
    }
    struct in_addr addr;
    if (inet_aton(argv[1], &addr) == 0) {
        fprintf(stderr, "Invalid address\n");
        exit(1);
    }
    printf("0x%x\n", ntohl(addr.s_addr));
}