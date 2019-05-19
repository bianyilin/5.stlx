/*************************************************************************
	> File Name: user.c
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月18日 星期六 10时39分03秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *env[]) {
    int n, i = 0;
    char file[1000], user[10000];
    while(1) {
        if('U' == env[i][0] && 'S' == env[i][1] && 'E' == env[i][2] && 'R' == env[i][3]) {
            strcpy(user,env[i]);
            break;
        }
        i++;
    }
	sscanf(user, "USER=%s", user);
    strcpy(file, argv[0]);
    if(strcmp(argv[0], "./haizeix") == 0 && strcmp(user, "bianyilin") == 0) {
        printf("%s\n", user);
        printf("可执行\n");
        printf("\n");
    } else {
        printf("不可执行\n");
        exit(0);
    }
	return 0;
}
