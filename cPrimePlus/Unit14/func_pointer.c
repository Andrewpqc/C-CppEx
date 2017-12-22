/**
 * 申明函数指针最简单的方法,先声明函数原型，然后将函数原型中的函数名
 * 改为(*fp),那么fp就是指向该函数的指针。函数名就是指向该函数的指针
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a,int b){
    return a+b;
}

int func(char a){
    int b=a-'0';
    return b;
}

int main (void){
    /**
     * 下面这句话申明了一个指针变量，该指针变量指向
     * 一个函数，这个函数的类型是：“返回值是int类型
     * 参数是int,int”
     **/ 
    int (*fp)(int,int);

    //我们上面定义的add函数的类型就是与我们申明的函数指针类型相匹配
    //所以可以直接将上面的add函数赋值给fp，就像下面这样
    fp=add;

    //然后我们就可以使用(*fp)或fp替代这个函数名了，目前这两种方式都支持
    printf("%d",fp(1,2));
    printf("%d",(*fp)(1,2));

    // fp=func;//这是错误的，因为func与fp的类型不对应
    
    int (*fp2)(char);
    fp2=func;//这才是对的

    
    printf("%d",add==fp);
    return 0;
}