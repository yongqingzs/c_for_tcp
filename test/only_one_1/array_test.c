/* no_data.c -- 为初始化数组 */
#include <stdio.h>
#include <string.h>

#define SIZE 4

int main(void)
{
    int array_test(void);
    int array_test_0(void);
    int array_test_1(void);
    int designate(void);
    int bound(void);
    int rain(void);
    int two_test(void);

    int type = 6;
    switch (type)
    {
        case 0:
            array_test();
            break;
        case 1:
            array_test_0();
            break;
        case 2:
            array_test_1();
            break;
        case 3:
            designate();
            break;
        case 4:
            bound();
            break;    
        case 5:
            rain();
            break;
        case 6:
            two_test();
            break;
        default:
            break;
    }
}


int array_test(void)
{
    int no_data[SIZE];  /* 未初始化数组 */
    int i;

    memset(no_data, 0, sizeof(no_data));
    printf("%2s%14s\n",    "i", "no_data[i]");
    for (i = 0; i < SIZE; i++)
        printf("%2d%14d\n", i, no_data[i]);
    printf("%14d\n", no_data[4]);

    return 0;
}


int array_test_0(void)
{
    int some_data[SIZE] = { 1492, 1066 };
    int i;

    printf("%2s%14s\n",    "i", "some_data[i]");
    for (i = 0; i < SIZE; i++)
        printf("%2d%14d\n", i, some_data[i]);

    return 0;
}


int array_test_1(void)
{
    const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 };
    int index;

    for (index = 0; index < sizeof days / sizeof days[0]; index++)
        printf("Month %2d has %d days.\n", index + 1, days[index]);

    return 0;
}


#define MONTHS 12
int designate(void)
{
    // int days[MONTHS] = { 31, 28, [4] = 31, 30, 31, [1] = 29 };
    int days[MONTHS] = { [1] = 29 };
    int i;

    for (i = 0; i < MONTHS; i++)
        printf("%2d  %d\n", i + 1, days[i]);

    return 0;
}


#define SIZE 4
int bound(void)
{
    int value1 = 44;
    int arr[SIZE];
    int value2 = 88;
    int i;

    printf("value1 = %d, value2 = %d\n", value1, value2);
    for (i = -1; i <= SIZE; i++)
        arr[i] = 2 * i + 1;

    for (i = -1; i < 7; i++)
        printf("%2d %d\n", i, arr[i]);
    printf("value1 = %d, value2 = %d\n", value1, value2);
    printf("address of arr[-1]: %p\n", &arr[-1]);
    printf("address of arr[4]: %p\n", &arr[4]);
    printf("address of value1: %p\n", &value1);
    printf("address of value2: %p\n", &value2);

    return 0;
}


#define MONTHS 12        // 一年的月份数
#define YEARS   5        // 年数

int rain(void)
{
    // 用2010～2014年的降水量数据初始化数组
    const float rain[YEARS][MONTHS] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };
    int year, month;
    float subtot, total;

    printf(" YEAR    RAINFALL  (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++)
    {                     // 每一年，各月的降水量总和
        for (month = 0, subtot = 0; month < MONTHS; month++)
             subtot += rain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;  // 5年的总降水量
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");

    for (month = 0; month < MONTHS; month++)
    {                    // 每个月，5年的总降水量
        for (year = 0, subtot = 0; year < YEARS; year++)
             subtot += rain[year][month];
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\n");

    return 0;
}


int two_test(void)
{
    int two[2][3];

    memset(two, 0, sizeof(two));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            printf("%d\n", two[i][j]);
}
