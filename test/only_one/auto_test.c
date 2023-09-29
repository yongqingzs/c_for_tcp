#include <stdio.h>


int main(void)
{
    int loop(int);
    int hiding(void);
    int hiding_for_c99(void);
    int auto_init(void);

    int type = 3;
    switch (type)
    {
    case 0:
        loop(10);
        break;
    case 1:
        hiding();
        break;
    case 2:
        hiding_for_c99();
        break;
    case 3:
        auto_init();
        break;
    default:
        break;
    }
}


int loop(int n)
{
    int m;
    float i = 6.6;
    scanf("%d", &m);
    {
        int i;
        for (i = m; i < n; i++)
        {
            puts("i is local to a sub-block\n");
        }
        return m;
    }
}


int hiding(void)
{
    int x = 30;

    printf("x in outer block: %d at %p\n", x, &x);  // x1

    {
        int x = 77;
        printf("x in inner block: %d at %p\n", x, &x);  // x2
    }

    printf("x in outer block: %d at %p\n", x, &x);  // x1
    
    while (x++ < 33)  // x1
    {
        int x = 100;
        x++;
        printf("x in while loop: %d at %p\n", x, &x);  // x3
    }
    printf("x in outer block: %d at %p\n", x, &x);  // x1
    
    return 0;
}


int hiding_for_c99(void)
{
    int n = 8;

    printf("   Initially, n = %d at %p\n", n, &n);  // n1
    
    for (int n = 1; n < 3; n++)
        printf("      loop 1: n = %d at %p\n", n, &n);  // n2
    
    printf("After loop 1, n = %d at %p\n", n, &n);  // n1
    
    for (int n = 1; n < 3; n++)
    {
        printf(" loop 2 index n = %d at %p\n", n, &n);  // n3
        int n = 6;  // n2(本来应该是n4，但是实现了对n2的复用)
        printf("      loop 2: n = %d at %p\n", n, &n);
        n++;  // n2
    }
    
    printf("After loop 2, n = %d at %p\n", n, &n);  // n1

    return 0;
}


int auto_init(void)
{
    int repid;
    int tents = 5;
    printf("repid = %d at %p\n", repid, &repid);
    printf("tents = %d at %p\n", tents, &tents);
}

