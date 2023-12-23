#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int * ptr_test(void);
    int ptr_test_0(int ** p);
    int * ptr_test_1(void);

    int type = 3;
    switch (type)
    {
    case 0:
        int * p = ptr_test();
        for (int i = 0; i < 5; i++)
        {
            printf("%d\n", *(p + i));
        }
        break;
    case 1:
        int * p_0;
        int flag = ptr_test_0(&(p_0));
        if (flag == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                printf("%d\n", *(p_0 + i));
            }
        }
        break;
    case 2:
        int * p_1 = ptr_test_1();
        for (int i = 0; i < 5; i++)
        {
            printf("%d\n", *(p_1 + i));
        }
        break;
    case 3:
        // int * p_2;
        int * p_2 = (int *) malloc(sizeof(int));
        printf("%d\n", *p_2);
        *p_2 = 1;
        printf("%d\n", *p_2);
        break;
    default:
        break;
    }
}


int * ptr_test(void)
{
    int * p;
    int a[] = {1, 2, 3, 4, 5};
    p = a;
    return p;
}


int ptr_test_0(int ** p)
{
    int * p_mall;
    p_mall = (int *) malloc(5 * sizeof(int));
    if (p_mall == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    p_mall[0] = 1;
    p_mall[1] = 2;
    p_mall[2] = 3;
    p_mall[3] = 4;
    p_mall[4] = 5;
    *p = p_mall;
    return 0;
}


int * ptr_test_1(void)
{
    int * p_mall;
    p_mall = (int *) malloc(5 * sizeof(int));
    if (p_mall == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    p_mall[0] = 1;
    p_mall[1] = 2;
    p_mall[2] = 3;
    p_mall[3] = 4;
    p_mall[4] = 5;
    return p_mall;
}
