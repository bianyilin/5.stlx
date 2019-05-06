/*************************************************************************
	> File Name: shuzudizhi.c
	> Author: bianyilin
	> Mail: 732406982@qq.com 
	> Created Time: 2019年05月04日 星期六 16时48分47秒
 ************************************************************************/

#include <stdio.h>

//*(arr + i)
//arr[i]
//int func_1(int *a) {//a形参
//    printf("sizeof(*a) = %lu\n", sizeof(a));
 //   *(a + 0) = 123;//等价
 //   a[0] = 123;
 //   *a = 123;
 //   return 0;
//}

int func_2(int **a) {
 //   a[0][1] = 123;
 //   a[2][3]  = *(a[2]+3) = (a[2]+3)[0] = *(*(a+2)+3) =
 //   *(*(&a[0]+2)+3) = *((&a[2])[0]+3) = (a+2)[0][3] =
 //   (*(a+2)+3)[0]
    a[2][3];
    a[0][1] = 123;
    return 0;
}

int main() {
    int arr[100][200];
    printf("&arr[0] = %p arr = %p\n", &arr[0], arr);
    printf("arr+ 1 = %p arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char*)arr;
    printf("p + 1 = %p  p + 2 = %p\n", p + 1, p + 2);
    printf("sizeof(arr) = %lu\n", sizeof(arr));
   // func(&n);//实参
   // func_1(arr);
   // func_2(arr);
    return 0;
}

