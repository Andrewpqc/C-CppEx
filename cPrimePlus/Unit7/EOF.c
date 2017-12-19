#include <stdio.h>

int main (void){
    char ch;
    while((ch=getchar())!=EOF)
        putchar(ch);
    return 0;
}

/**
 * linux通过Ctrl+D发送文件结尾信号
 */ 