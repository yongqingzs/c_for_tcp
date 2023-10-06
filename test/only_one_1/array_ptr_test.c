#include <stdio.h>
#include <string.h>


int main(void)
{
    int ptr_test(void);
    int ptr_test_0(void);
    int sum_array(void);
    int sum_array_0(void);
    int ptr_ops(void);
    int ptr_init_test(void);

    int type = 5;
    switch (type)
    {
        case 0:
            ptr_test();
            break;
        case 1:
            ptr_test_0();
            break;
        case 2:
            sum_array();
            break;
        case 3:
            sum_array_0();
            break;
        case 4:
            ptr_ops();
            break;
        case 5:
            ptr_init_test();
            break;
        default:
            break;
    }
}


#define SIZE 4
int ptr_test(void)
{
    short dates[SIZE];
    short * pti;
    short index;
    double bills[SIZE];
    double * ptf;
    pti = dates;    // 把数组地址赋给指针
    ptf = bills;
    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index++)
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    return 0;
}


int ptr_test_0(void)
{
    int array_0[5];
    int * ptr_0;
    ptr_0 = array_0;

    memset(ptr_0, 0, sizeof(array_0));
    ptr_0[3] = 5;
    ptr_0[2]++;

    for (int i = 0; i < 5; i++)
        printf("%d\n", ptr_0[i]);
    printf("====================\n");
    for (int i = 0; i < 5; i++)
        printf("%d\n", *(array_0 + i));
}


#undef SIZE
#define SIZE 10
int sum_array(void)
{   
    int sum(int ar[], int n);
    int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long answer;

    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n",
        sizeof marbles);

    return 0;
}


int sum(int ar[], int n)     // 这个数组的大小是？
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];
    printf("The size of ar is %zd bytes.\n", sizeof &(ar[0]));  
    // &(ar[0]) == &(ar) == ar，但ar会报错

    return total;
}


#undef SIZE
#define SIZE 10
int sum_array_0(void)
{   
    int sump(int * start, int * end);

    int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long answer;
    
    answer = sump(marbles, marbles + SIZE);
    printf("The total number of marbles is %ld.\n", answer);

    return 0;
}


/* 使用指针算法 */
int sump(int * start, int * end)
{
    int total = 0;

    while (start < end)
    {
        total += *start;    // 把数组元素的值加起来
        start++;            // 让指针指向下一个元素
    }

    return total;
}


int ptr_ops(void)
{
    int urn[5] = { 100, 200, 300, 400, 500 };
    int * ptr1, *ptr2, *ptr3;

    ptr1 = urn;            // 把一个地址赋给指针
    ptr2 = &urn[2];        // 把一个地址赋给指针
                           // 解引用指针，以及获得指针的地址
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    // 指针加法
    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));
    ptr1++;                // 递增指针
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
    ptr2--;                // 递减指针
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
    --ptr1;                // 恢复为初始值
    ++ptr2;                // 恢复为初始值
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
    // 一个指针减去另一个指针
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);
    // 一个指针减去一个整数
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);

    return 0;
}


int ptr_init_test(void)
{
    int * pt;    // 未初始化的指针
    int data = 5;
    // *pt = data;         // 严重的错误
    pt = &(data);
    printf("%d\n", *pt);

    // int urn[3];
    // int * ptr1, * ptr2;
    // // true
    // ptr1++;
    // ptr2 = ptr1 + 2;
    // ptr2 = urn + 1;
    // // error
    // // urn++;
    // // ptr2 = ptr2 + ptr1;
    // // ptr2 = urn * ptr1;
}

