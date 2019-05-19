/*************************************************************************
	> File Name: test.h
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月18日 星期六 18时33分50秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include <stdio.h>
#include <stdlib.h>

typedef void (*FuncType)();

typedef struct FuncData {
    FuncType func;
    const char *name_part1;
    const char *name_part2;
    struct FuncData *next;
} FuncData, *pFuncData;

static pFuncData head = NULL;

typedef struct TotalData {
    int succ, fail;
} TotalData;
static TotalData info;

void clear_TotalData() {
    info.succ = info.fail = 0;
}

void add_success() {
    info.succ += 1;
}
void add_failed() {
    info.fail += 1;
}


#define __FuncName(a, b) a##b
#define FuncName(a, b) __FuncName(a, b)
#define STR(a) #a

#define TEST(a, b) \
void FuncName(a, FuncName(_, FuncName(b, FuncName(_, Test))))();\
__attribute__((constructor)) void FuncName(add_Test, __COUNTER__)() { \
    pFuncData p = (pFuncData)malloc(sizeof(FuncData));\
    p->func = FuncName(a, FuncName(_, FuncName(b, FuncName(_, Test)))); \
    p->name_part1 = STR(a); \
    p->name_part2 = STR(b); \
    p->next = head; \
    head = p; \
}\
void FuncName(a, FuncName(_, FuncName(b, FuncName(_, Test))))()

#define EXPECT_EQ(a, b) {\
    __typeof(a) __temp_a = a, __temp_b = b;\
    if (__temp_a == __temp_b) add_success();\
    else add_failed();\
    printf("%s = %s %s\n",#a, #b, __temp_a == __temp_b ? "True" : "False");\
}

#define EXPECT_NE(a,b)
#define EXPECT_GT(a,b)
#define EXPECT_LT(a,b)
#define EXPECT_LE(a,b)
#define EXPECT_GE(a,b)

#define COLOR(a,b)"\033[" #b "m" a"\033[0m"


#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)
#define BLUE(a) COLOR(a, 34)

void output_info() {
    double rate = 1.0 * info.succ / (info.succ + info.fail);
    const char *output_str = NULL;
    char output_frm[100];
    if(info.fail == 0) output_str = BLUE("%6.2lf%%");
    else output_str = RED("%6.2lf%%");
    sprintf(output_frm, "[ %s ] total : %%3d expect : %%3d\n", output_str);
    printf(output_frm, rate * 100, info.succ + info.fail, info.succ);
    return ;
}

int RUN_ALL_TESTS() {
    pFuncData p = head;
    while (p != NULL) {
        printf("[ " GREEN("RUN") "]%s.%s\n",p->name_part1, p->name_part2);
        clear_TotalData();
        p->func();
        p = p->next;
        output_info();
    }
    return 0;
}

#endif
