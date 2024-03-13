#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("Command line arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    printf("\nEnvironment variables:\n");
    for (int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }

    return 0;
}