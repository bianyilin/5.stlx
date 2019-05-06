/*************************************************************************
	> File Name: erfenchazhao.c
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月04日 星期六 15时18分45秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>

int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid -1;
    }
    return -1;
}

int arr[100];

double my_sqrt(double y) {
    #define EXP 1e-7
    double head = 0, tail = y, mid;
    while (tail - head >EXP) {
        mid = (head + tail) / 2.0;
        if (mid * mid < y) head = mid;
        else tail = mid;
    }
    return head;
}

double f(double x, double y) {
    return x * x - y;
}

double f_prime(double x) {
    return 2 * x;
}

double newton_sqrt(double y) {
    #define EXP 1e-7
    double x = 0;
    while (fabs(f(x, y)) > EXP) {
        x = x - (f(x, y) / f_prime(x));
    }
    return x;
}

float god_sqrt (float x) {
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f375a86- (i>>1);//雷神之锤
    x = *(float*)&i;
    x = x*(1.5f-xhalf*x*x);
    x = x*(1.5f-xhalf*x*x);
    x = x*(1.5f-xhalf*x*x);
    return 1/x;
}

#define TEST_FUNC(func,TIMES) {\
    int b = clock();\
    for (int i = 0; i < TIMES; i++) {\
        double temp = func((double)(1.0 * i));\
    }\
    int e = clock();\
    printf("TEST %s : %lf s\n", #func,1.0 * (e-b) / CLOCKS_PER_SEC);\
}

int main() {
    TEST_FUNC(god_sqrt, 10000000);
    TEST_FUNC(newton_sqrt, 10000000);//牛顿迭代
    TEST_FUNC(sqrt, 10000000);
    TEST_FUNC(my_sqrt, 10000000);
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    while (~scanf("%d", &a)) {
        printf("binary_search result = %d\n", binary_search(arr,n, a));
    }
    return 0;
}

