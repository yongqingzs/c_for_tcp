#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_2d_array_0(int m, int n, int array[m][n]);

int read_2d_array_1(int m, int n, int array[m][n]);

void fill_2d_array_with_random_numbers(int row_size, int col_size, int arr[row_size][col_size]);

int main() {
    clock_t start, end;
    double cpu_time_used;

    // 往一个数组里存取随机数
    int m = 1000, n = 1000;
    int test_array[m][n];
    fill_2d_array_with_random_numbers(m, n, test_array);

    // 测量 read_2d_array_0 的运行时间
    start = clock();
    for(int i = 0; i < 1000; i++) {
        read_2d_array_0(m, n, test_array);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("read_2d_array_0 运行时间: %f seconds\n", cpu_time_used);

    // 测量 read_2d_array_1 的运行时间
    start = clock();
    for(int i = 0; i < 1000; i++) {
        read_2d_array_1(m, n, test_array);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("read_2d_array_1 运行时间: %f seconds\n", cpu_time_used);

    return 0;
}

int read_2d_array_0(int m, int n, int array[m][n])
{
    int sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            sum += array[i][j];
    }
    return sum;
}

int read_2d_array_1(int m, int n, int array[m][n])
{
    int sum = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++)
            sum += array[i][j];
    }
    return sum;
}

void fill_2d_array_with_random_numbers(int row_size, int col_size, int arr[row_size][col_size]) {
    // 使用当前时间作为随机数生成器的种子
    #include <stdlib.h>

    for(int i = 0; i < row_size; i++) {
        for(int j = 0; j < col_size; j++) {
            // 生成一个随机数并存储到二维数组中
            arr[i][j] = rand() % 100;  // 生成0到99的随机数
        }
    }
}
