#include <stdio.h>
#include <string.h>

int bzero_test(void);
int memset_test(void);

int main(void)
{
    int type = 1;
    switch (type)
    {
        case 0:
            bzero_test();
            break;
        case 1:
            memset_test();
            break;
        default:
            break;
    }
}


int bzero_test(void)
{
    int array_0[5] = {1, 2, 3, 4, 5};
    bzero(array_0, sizeof(array_0));
    int *p;
    p = array_0;
    printf("%d\n", *p);
    printf("%d\n", *(p+1));
}


int memset_test(void)
{
    int array_0[5] = {1, 2, 3, 4, 5};
    memset(array_0, -1, sizeof(array_0));
    int *p;
    p = array_0;
    printf("%d\n", *p);
    printf("%d\n", *(p+1));
}
