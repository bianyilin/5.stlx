/*************************************************************************
	> File Name: 4207.c
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年04月20日 星期六 20时44分04秒
 ************************************************************************/

#include <stdio.h>

int f(int k, int b, int x) {
    return k * x + b;
}

int main() {
    int k, b;
    scanf("%d%d", &k, &b);
    for(int i = 1; i <= 100; ++i) {
        printf("f(%d) = %d\n", i, f(k, b, i));
    }
    return 0;
}

