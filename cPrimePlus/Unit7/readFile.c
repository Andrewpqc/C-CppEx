/**
 * 读取文件的内容输出到stdout
 */ 
#include <stdio.h>
#include <stdlib.h>
int main (void){
    FILE* f;
    char ch;
    f=fopen("EOF.c","r");
    while((ch=getc(f))!=EOF){
        putchar(ch);
    }
    fclose(f);
    return 0;
}