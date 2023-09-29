#include <stdio.h>


int profun_test_0(int, int);
int const_test_0(void);
int const_test_1(void);


int main(void)
{
    // const_test_1();
    profun_test_0(2.0, 3.0);
}


int profun_test_0(int n, int m)
{   
    int temp;
    temp = n > m ? n : m;
    printf("temp: %d\n", temp);
}


int const_test_0(void)
{
    const int type = 4;

    const int i1 = 10;
    const float f1 = 10.0;
    const float f2 = 10.1;
    float f3 = 10.2;

    const float *pf; 
    float * const cpf = &(f3);
    switch (type)
    {   
        case 1:
            printf("i1: %d\n", i1);
            break;
        case 2:  
            pf = &(f1);
            printf("pf1: %f\n", *pf);
            pf = &(f2);
            printf("pf2: %f\n", *pf);
            break;
        case 3:  
            printf("cpf1: %f\n", *cpf);
            break;
        case 4:
            pf = &(f3);
            printf("pf3: %f\n", *pf);
            break;
        default:
            break;
    }
}


int const_test_1(void)
{
    float rank[10];
    for(int i = 0; i < 10; i++)
    {
        rank[i] = i + 1;
    }
    float temp = 0;
    int entity = 2;

    temp = *(rank + 2 * entity);  
    printf("temp: %f\n", temp);
}
