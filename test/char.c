#include <stdio.h>

int main(void)
{
    int char_test(void);
    char_test();
    return 0;
}

int char_test(void)
{
    char c1 = 'a';
    char *c2 = "abc";
    printf("c1 = %c\n", c1);
    printf("c2 = %c\n", c2[2]);
    return 0;
}
