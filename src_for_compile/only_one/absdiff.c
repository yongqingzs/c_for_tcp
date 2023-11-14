/* 
为了查看编译后不同的条件分支，
当使用gcc -O1 -S absdiff.c进行编译时，
出来的是两种不同的分支实现
 */
long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y) 
{
    // 条件转移
    long result;
    if (x < y) 
    {
        lt_cnt++;
        result = y - x;
    } 
    else 
    {
        ge_cnt++;
        result = x - y;
    }
    return result;
}

long absdiff(long x, long y)
{   
    // 条件传送
    long result;
    if (x < y)
        result = y - x;
    else
        result = x - y;
    return result;
}
