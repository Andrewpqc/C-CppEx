#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
    // int a[2]={1,2};
    // int b[2];
    // a=b;
    //以上三行代码非法！！！！！！不能把一个数组赋值给另一个数组

    //下面这种将一个数组赋值给另外一个数组的方法才是对的
    int a[2]={1,2};
    int b[2];
    for(int i=0;i<2;i++)
        b[i]=a[i];
    for(int j=0;j<2;j++)
        printf("%d ",b[j]);
    printf("\n");

    //有更好的方法吗？
    double c[2]={1.0,2.0};
    double d[2];
    memcpy(d,c,2*sizeof(double));//更加优雅的方式
    //但是这个函数假设的是c,d两者之间占用的内存不重叠，如果两者之间占用的内存重叠的话
    //程序的行为是不确定的。
    for(int i=0;i<2;i++)
        printf("%lf ",d[i]);

    printf("\n");
    //memmove()也可以达到相同的功能
    int e[2]={1,2};
    int f[2];
    memmove(f,e,2*sizeof(int));
    //与memcpy不同，memmove不做e,f两者之间内存不重叠的假设，也就是说，memmove现将e中的内存拷贝到
    //一个缓冲区，然后在拷贝到目的地f中
    for(int i=0;i<2;i++)
        printf("%d ",f[i]);
    return 0;
}