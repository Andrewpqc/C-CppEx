/**
 * 原来可变参数是这样搞得啊　stdarg.h
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int mysum(int count,...){
    int sum=0;
    va_list vl1,vl2;
    va_start(vl1,count);
    va_copy(vl2,vl1);
   
    for(int i=0;i<count;i++){
        printf("%d ",va_arg(vl2,int));
        sum+=va_arg(vl1,int);
    }
    // printf("\n");
    va_end(vl1);
    va_end(vl2);
    return sum;
}

int main (void){
    int sum1=mysum(2,1,2);
    printf("%d",sum1);//3
    int sum2=mysum(5,1,2,3,4,5);
    printf("\n%d",sum2);//15
    return 0;
}


