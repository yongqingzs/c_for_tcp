/* preproc.c -- 简单的预处理示例 */
#include <stdio.h>
#include <math.h>
#define TWO 2        /* 可以使用注释 */
#define TWO 2        // 重定义
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde" /* 反斜杠把该定义延续到下一行 */
#define FOUR  TWO*TWO
#define PX printf("X is %d.\n", x)
#define FMT  "X is %d.\n"
#define FMT_0  "X is %d.\n"

// #define SQUARE(X) X*X
#define SQUARE(X) (X)*(X)
#define PR(X)   printf("The result is %d.\n", X)


int preproc_test_0(void);
int preproc_test_1(void);
int preproc_test_2(void);
int preproc_test_3(void);


int main(void)
{
    int type = 3;
    switch (type)
    {
        case 0:
            preproc_test_0();
            break;
        case 1:
            preproc_test_1();
            break;
        case 2:
            preproc_test_2();
            break;
        case 3:
            preproc_test_3();
            break;
        default:
            break;
    }
}


int preproc_test_0(void)
{
    int x = TWO;

    PX;
    x = FOUR;

    char temp[] = FMT_0;

    printf(FMT, x);
    printf("%s\n", OW);
    printf("TWO: OW\n");

    return 0;
}


int preproc_test_1(void)
{
    int x = 5;
    int z;

    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z);
    z = SQUARE(2);
    printf("Evaluating SQUARE(2): ");
    PR(z);
    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x + 2));
    printf("Evaluating 100/SQUARE(2): ");
    PR(100 / SQUARE(2));
    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x));
    printf("After incrementing, x is %x.\n", x);

    return 0;
}


#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))

int preproc_test_2(void)
{
    int y = 5;

    PSQR(y);
    PSQR(2 + 4);

    return 0;
}


#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);

int preproc_test_3(void)
{
    int XNAME(1) = 14;      // 变成 int x1 = 14;
    int XNAME(2) = 20;     // 变成 int x2 = 20;
    int x3 = 30;
    PRINT_XN(1);            // 变成 printf("x1 = %d\n", x1);
    PRINT_XN(2);            // 变成 printf("x2 = %d\n", x2);
    PRINT_XN(3);            // 变成 printf("x3 = %d\n", x3);
    return 0;
}


// #define PR_0(X, ...) printf("Message " #X ": " _ _VA_ARGS_ _)

// int preproc_test_4(void)
// {
//     double x = 48;
//     double y;

//     y = sqrt(x);
//     PR_0(1, "x = %g\n", x);
//     PR_0(2, "x = %.2f, y = %.4f\n", x, y);

//     return 0;
// }

