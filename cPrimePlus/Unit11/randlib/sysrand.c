#include <stdio.h>
#include <stdlib.h>　//提供rand的原型

int main (void){
    for(int i=0;i<10;i++){
        int a=rand()%6+1; //这里的rand也是一个伪随机数
        printf("%d\n",a);　
    }
    return 0;
}