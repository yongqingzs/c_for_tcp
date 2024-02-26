#include <stdio.h>

double d_ex_0 = 9.9;

int main(void)
{
    // extern double d_ex_0;  // 可以不需要
    extern int i_ex_0;
    // int i_ex_0;  // 不会引用外部变量，21860
    printf("d_ex_0 = %f\n", d_ex_0);
    d_ex_0 = 8.8;
    printf("d_ex_0 = %f\n", d_ex_0);
    printf("i_ex_0 = %d\n", i_ex_0);

    // extern int fun_for_ext_0(void);
    int fun_for_ext_0(void);  // 也可以正常运行
    fun_for_ext_0();
    return 0;
}
