#include <stdio.h>
#include <stdlib.h>

int malloc_test_0(void);
static int malloc_test_1(void);   // only for test static
static int free_test(void);
void calloc_test(void);
int vlamal_test(void);

int main(int argc, char *argv[])
{   
    // if (argc != 2) {
    //     printf("Usage: %s <number>\n", argv[0]);
    //     return 1;
    // }

    // int type = atoi(argv[1]);
    int type = 4;
    switch (type)
    {
        case 0:
            malloc_test_0();
            break;
        case 1:
            malloc_test_1();
            break;
        case 2:
            free_test();
            break;
        case 3:
            calloc_test();
            break;
        case 4:
            vlamal_test();
            break;
        default:
            break;
    }
    return 0;
}


int malloc_test_0(void)
{
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL) {
        printf("malloc failed\n");
        return -1;
    }
    *p = 10;
    printf("p = %d\n", *p);
    free(p);
    return 0;
}


static int malloc_test_1(void)
{
    double * ptd;
    int max;
    int number;
    int i = 0;

    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1)
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    ptd = (double *) malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    /* ptd 现在指向有max个元素的数组 */
    puts("Enter the values (q to quit):");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
        ++i;
    printf("Here are your %d entries:\n", number = i);
    for (i = 0; i < number; i++)
    {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    if (i % 7 != 0)
        putchar('\n');
    puts("Done.");
    free(ptd);

    return 0;
}


static int free_test(void)
{   
    // 只是为了演示内存泄漏
    void gobble(double *, int);
    double glad[2000];
    int i;
    for (i = 0; i < 10000; i++)
        gobble(glad, 2000);
}


void gobble(double ar[], int n)
{
    double * temp = (double *) malloc(n * sizeof(double));
    /* free(temp); // 假设忘记使用free() */
    printf("temp malloced at %p\n", temp);
}


void calloc_test(void)
{
    long * newmem;
    newmem = (long *) calloc(1000, sizeof(long));
    printf("calloc_test\n");
}


int vlamal_test(void)
{
    int n;
    int * pi;
    // scanf("%d", &n);
    n = 2;
    pi = (int *) malloc (n * sizeof(int));
    int ar[n];// 变长数组
    pi[2] = ar[2] = -5;
    printf("pi: %p, ar: %p\n", pi, ar);
}


int vlamal_test_0(void)
{
    int n = 5;
    int m = 6;
    int ar2[n][m]; // n×m的变长数组（VLA）
    int (* p2)[6]; // C99之前的写法
    int (* p3)[m]; // 要求支持变长数组
    p2 = (int (*)[6]) malloc(n * 6 * sizeof(int)); // n×6 数组
    p3 = (int (*)[m]) malloc(n * m * sizeof(int)); // n×m 数组（要求支持变长数组）
    ar2[1][2] = p2[1][2] = 12;
}
