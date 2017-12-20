/**
 * stdlib.h
 * atoi
 * atof
 * atol
 * 
 * 更安全的选择
 * strtol long
 * strtoul unsigned long
 * strtod double
 */ 


#include <stdio.h>
#include <stdlib.h>

int main(void){
    //字符串转换成数字
    int a=atoi("aaa"); //如果使用的是非数字字符，则返回0
    printf("%d\n",a+1);
    //输出１

    int b=atoi("a2b3");
    printf("%d\n",b);
    //输出０

    int c=atoi("321#1");//如果字符串前面的是数字字符的话，也可以转化成功
    printf("%d\n",c);
    //输出３２１

    double d=atof("2.13");
    printf("%f\n",d);
    //输出2.130000

    double f=atof("2.1dsf");
    printf("%f\n",f);
    //输出2.100000

    double g=atof("s3.2");
    printf("%f\n",g);
    //输出0.000000


    long e=atol("546565");
    printf("%ld\n",e);
    //输出546565

    return 0;
}