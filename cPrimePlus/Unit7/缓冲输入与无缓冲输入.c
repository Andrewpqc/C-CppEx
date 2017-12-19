/**
 * 
 * 无缓冲输入输出
 * 
 */ 
#include <stdio.h>
#include <conio.h>　//linux系统不支持这个头文件
int main (void){
    while(ch=getch()){
        putchar(ch);
    }
    return 0;
}