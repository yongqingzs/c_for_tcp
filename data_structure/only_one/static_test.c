#include <stdio.h>


int static_var_0 = 10;
static int static_var_1 = 20;
int units = 0;

int main(void)
{   
    int trystat_main(void);
    int static_var_test(void);
    int static_var_test_0(void);

    int type = 1;
    switch (type)
    {
    case 0:
        trystat_main();
        break;
    case 1:
        static_var_test();
        break;
    case 2:
        static_var_test_0();
    default:
        break;
    }
    
}


int static_var_test(void)
{
    extern int static_var_0;
    // extern int static_var_1;
    int static_var_1 = 30;
    printf("static_var_0: %d\n", static_var_0);
    printf("static_var_1: %d\n", static_var_1);
    static_var_0++;
    printf("static_var_0: %d\n", static_var_0);
}


int static_var_test_0(void)
{   
    int static_var_test_1(void);
    extern int units;  /* 可选的重复声明 */

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        static_var_test_1();
    printf("You must have looked it up!\n");

    return 0;
}


int static_var_test_1(void)
{
    /* 删除了可选的重复声明 */
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &units);
}


int trystat_main(void)
{
    void trystat(void);

    int count;
    for (count = 1; count <= 3; count++)
    {
        printf("Here comes iteration %d:\n", count);
        trystat();
    }

    return 0;
}


void trystat(void)
{
    int fade = 1;
    static int stay = 1;

    printf("fade = %d and stay = %d\n", fade++, stay++);
}
