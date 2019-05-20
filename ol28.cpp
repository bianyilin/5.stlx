/*************************************************************************
	> File Name: ol28.cpp
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月19日 星期日 20时07分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

int main() {
	int sum = 1;
    for (int l = 3; l <= 1001; l += 2) {
	sum += 4 * l * l - 6 * l + 6;
	}
	printf("%d\n",sum);
    return 0;
}

