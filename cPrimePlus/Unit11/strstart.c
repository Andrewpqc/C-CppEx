/**
 * 定义字符串的几种方法
 */ 
#include <stdio.h>
#define STR "hehehe"
int main (void){
    char a []="aaaaaaa";
    char* b="bbbbbbbbb";
    puts(STR);
    puts(a);
    puts(b);
    char s[10];
    //gets函数无法检查用户输入的字符串是否可以被s装下，所以不安全，不建议使用
    gets(s);
    puts(s);
    return 0;
}