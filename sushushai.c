/*************************************************************************
	> File Name: sushushai.c
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月04日 星期六 14时33分37秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if(prime[i]) continue;
        for(int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    //10000以内的所有素数
    for (int i = 2; i <= MAX_N; i++) {
        if(prime[i]) continue;
        printf("%d\n", i);
    //  prime[++printf[0]] = i;
    }
     //n以内最大素数
     int n;
     while (~scanf("%d", &n)) {
         printf("%d\n", prime[n]);
       }
    return 0;
}

