// names_st.h -- names_st 结构的头文件
// 常量
#include <string.h>
#define SLEN 32

// 结构声明
struct names_st
{
    char first[SLEN];
    char last[SLEN];
};

// 类型定义
typedef struct names_st names;

// 函数原型
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);

extern int status;  // 具有外部链接的静态变量声明
static int inner_status;  // 具有内部链接的静态变量声明，每个包含该头文件的源文件均会获得一份副本

