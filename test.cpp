/*************************************************************************
	> File Name: test.cpp
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月18日 星期六 17时32分30秒
 ************************************************************************/

#include "test.h"

int add(int a, int b){
    return a + b;
}

TEST(testCase, test0){
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(3, 3), 6);
    EXPECT_EQ(add(4, 3), 7);
    EXPECT_EQ(add(5, 3), 7);
    EXPECT_EQ(add(6, 3), 9);
    EXPECT_EQ(add(7, 3), 10);
}
TEST(testCase, test1) {
    EXPECT_EQ(add(2, 3), 5);
}

int main(int atgc,char**atgv){
  return RUN_ALL_TESTS();
}
