// useheader.c -- 使用 names_st 结构
#include <stdio.h>
#include "names_st.h"
// 记住要链接 names_st.c

int main(void)
{
    names candidate;
    // extern int status;

    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");

    // status
    printf("status: %d\n", status);

    // inner_status
    inner_status = 1;
    printf("inner_status: %d\n", inner_status);

    return 0;
}