/**
 * 自定义更加安全便捷的获取用户的一行输入
 * C标准IO中的的函数存在的问题：
 * scanf()读取到空白字符之后就停止，无法获取用户的一行输入
 * getc()不安全，不能对用户输入的数据的长度做限制
 * fgets()安全，但是会保留输入中的换行符，这个换行符通常不是我们想要的
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *安全的从标准输入获取指定长度的字符串，并且不保留换行符 
 * 
 */
char*  my_gets(char* a,int size){
    char* ret_val;
    char*temp;
    ret_val=fgets(a,size,stdin);
    if(ret_val){
        temp=strchr(a,'\n');
        if(temp){
            *temp='\0';
        }else{
            while(getchar()!='\n')
                continue;
        }
    }
    return ret_val;
}


int main (void){
    char a[10];
    my_gets(a,10);
    puts(a);
    return 0;
}