#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int * p;
    p = (int *)malloc(sizeof(int));
    printf("*p: %d, p: %p\n", *p, p);
}
