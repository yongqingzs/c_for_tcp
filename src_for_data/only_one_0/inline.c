#include <stdio.h>
inline static void eatline()    // 内联函数定义/原型
{
    while (getchar() != '\n')
        continue;
}

int main()
{
    eatline();            // 函数调用
}
