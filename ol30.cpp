/*************************************************************************
	> File Name: ol30.cpp
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月19日 星期日 20时37分07秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

#define MAX 354295

int is(int x) {
    int num = x, s = 0;
    while (x) {
        s += pow(x % 10, 5);
        x /= 10;
    }
    num = (num == s? num : x);
    return num;
}

int main() {
    int sum = 0;
    for (int i = 2; i <= MAX; i++) {
        sum += is(i);
    }
    printf("%d\n", sum);
    return 0;
}

