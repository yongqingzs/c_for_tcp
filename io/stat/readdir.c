#include "../../csapp.h"

int main(int argc, char **argv) {
    DIR *streamp;
    struct dirent *dep;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <directory>\n", argv[0]);
        exit(0);
    }
    streamp = Opendir(argv[1]);
    while ((dep = Readdir(streamp)) != NULL)
        printf("%s\n", dep->d_name);
    Closedir(streamp);
    exit(0);
}