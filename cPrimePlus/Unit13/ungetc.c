/**
 * ungetc()
 */

#include <stdio.h>
#include <stdlib.h>

int main (void){
    char ch=getc(stdin);
    putchar(ch);
    ungetc('w',stdin); //往输入流中放回一个字符
    char ch2=getc(stdin);//下次获取时获取的就上刚才放入的那个字符
    putchar(ch2);
    return 0;
}