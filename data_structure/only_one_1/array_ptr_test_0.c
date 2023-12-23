#include <stdio.h>


int main(void)
{   
    int afc(void);
    int two_ptr(void);
    int two_ptr_0(void);
    int two_ptr_1(void);
    int two_ptr_2(void);
    int two_ptr_3(void);

    int type = 5;
    switch (type) 
    {
        case 0:
            afc();
            break;
        case 1:
            two_ptr();
            break;
        case 2:
            two_ptr_0();
            break;
        case 3:
            two_ptr_1();
            break;
        case 4:
            two_ptr_2();
            break;
        case 5:
            two_ptr_3();
            break;
        default:
            break;
    }
}


#define SIZE 5
int afc(void)
{
    void show_array(const double ar[], int n);
    void mult_array(double ar[], int n, double mult);
    double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };

    printf("The original dip array:\n");
    show_array(dip, SIZE);
    mult_array(dip, SIZE, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(dip, SIZE);

    return 0;
}


/* 显示数组的内容 */
void show_array(const double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%8.3f ", ar[i]);
    putchar('\n');
}


/* 把数组的每个元素都乘以相同的值 */
void mult_array(double ar[], int n, double mult)
{
    int i;

    for (i = 0; i < n; i++)
        ar[i] *= mult;
}


int two_ptr(void)
{
    int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };

    printf("   zippo = %p,    zippo + 1 = %p\n",zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n",zippo[0], zippo[0] + 1);
    printf("  *zippo = %p,   *zippo + 1 = %p\n",*zippo, *zippo + 1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));

    return 0;
}


int two_ptr_0(void)
{
    int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };
    int(* pz)[2];
    pz = zippo;

    printf("   pz = %p,    pz + 1 = %p\n",    pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n",    pz[0], pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n",    *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));

    return 0;
}


int two_ptr_1(void)
{
    int * pt;
    int (*pa)[3];
    int ar1[2][3];
    int ar2[3][2];
    int **p2;    // 一个指向指针的指针

    pt = &ar1[0][0];    // 都是指向int的指针
    printf("ar1[0]: %p\n", ar1[0]);
    printf("ar1: %p\n", ar1);
    pt = ar1[0];        // 都是指向int的指针
    // pt = ar1;           // 无效
    pa = ar1;           // 都是指向内含3个int类型元素数组的指针
    // pa = ar2;           // 无效
    p2 = &pt;           // both pointer-to-int *
    *p2 = ar2[0];       // 都是指向int的指针
    // p2 = ar2;           // 无效
}


int two_ptr_2(void)
{
    int x = 20;
    const int y = 23;
    int * p1 = &x;
    const int * p2 = &y;
    const int ** pp2;
    // p1 = p2;      // 不安全 -- 把const指针赋给非const指针
    p2 = p1;      // 有效 -- 把非const指针赋给const指针
    // pp2 = &p1;    // 不安全 -- 嵌套指针类型赋值
}


int two_ptr_3(void)
{
    const int ** pp2;
    int * p1;
    const int n = 13;
    pp2 = &p1;    // 允许，但是这导致const限定符失效（根据第1行代码，不能通过*pp2修改它所指向的内容）
    *pp2 = &n;    // 有效，两者都声明为const，但是这将导致p1指向n（*pp2已被修改）
    printf("*p1: %d\n", *p1);
    * p1 = 10; //有效，但是这将改变n的值（但是根据第3行代码，不能修改n的值）
    printf("*p1: %d\n", *p1);
}
