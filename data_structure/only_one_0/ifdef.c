/* ifdef.c -- 使用条件编译 */
#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int ifdef_test_0(void);
int ifdef_test_1(void);

// #if __STDC_VERSION__ != 201112L
// #error Not C11
// #endif

int main(void)
{   
    int type = 1;
    
    switch (type)
    {
    case 0:
        ifdef_test_0();
        break;
    case 1:
        ifdef_test_1();
        break;
    default:
        break;
    }
    
    return 0;
}


int ifdef_test_0(void)
{
    int i;
    int total = 0;

    for (i = 1; i <= LIMIT; i++)
    {
        total += 2 * i*i + 1;
#ifdef JUST_CHECKING
        printf("i=%d, running total = %d\n", i, total);
#endif
    }
    printf("Grand total = %d\n", total);

    return 0;
}


int ifdef_test_1(void)
{
    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);
    printf("The version is %ld.\n", __STDC_VERSION__);
    printf("This is line %d.\n", __LINE__);
    printf("This function is %s\n", __func__);
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
}
