/*************************************************************************
	> File Name: structip.c
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月16日 星期四 18时56分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

union IP {
    unsigned int num;
    unsigned char ip[4];
 };

int is_little() {
    static int a = 1;
    return ((char *)(&a))[0];
}

int main() {
    //printf("%d\n", is_little());
    char ip_str[25];
    while (~scanf("%s",ip_str)) {
        int a, b, c, d;
        sscanf(ip_str,"%d.%d.%d.%d",&a, &b, &c, &d);
        union IP ip;
        ip.ip[3] = a;
        ip.ip[2] = b;
        ip.ip[1] = c;
        ip.ip[0] = d;
        printf("%s = %u\n", ip_str, ip.num);
    }
    return 0;
}

