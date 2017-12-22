/**
 * //内置快速排序的函数原型
 * void qsort(void* base,size_t nmemb,size_t size,int (* comptr)(const void *,const void *));
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_condition(const void * a,const void *b){
    //理解下面这两句
    const double * p1=(double*)a;
    const double * p2=(double*)b;
    if(*p1==*p2)
        return 0;
    else if(*p1>*p2)
        return 1;
    else
        return -1;
}

int main (void){
    double a [5]={100.0,2.0,20.0,4.0,5.0};
    qsort(a,5,sizeof(double),compare_condition);
    for(int i=0;i<5;i++)
        printf("%f ",a[i]);
    return 0;
}