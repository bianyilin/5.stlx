/*************************************************************************
	> File Name: 4206.c
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年04月20日 星期六 19时11分04秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        i == 0 || printf(" ");
        printf("%d", val);
        cnt += !(val & 1);
    }
    printf("\n");
    printf("cnt = %d\n", cnt);
    return 0;
}

