/**
 * string.h
 * strlen
 * strcat strncat
 * strcmp strncmp
 * strcpy strncpy
 * strchr strrchr
 * strpbrk
 * strstr
 */ 

#include <stdio.h>
#include <string.h>

int main (void){
    char a[100]="dsfgh";
    int len=strlen(a);
    // printf("%d",len);

    char* b="aaaaaaaa";
    //把b拼接到了a后面
    strcat(a,b);

    //C语言的字符串的比较用strcmp
    char c[19]="cbc";
    char d[10]="abc";
    if(strcmp(c,d)){ //俩个参数所指向的字符串相同则返回０，否则返回非零值
        puts("True");
    }else{
        puts("False");
    }

    char e[10];
    // e="dsf";　//错误
    strcpy(e,"dsfd"); //这样才正确
    puts(e);
    puts(a);

    //看某一个字符串包含不包含某一个字符
    //包含则返回该字符串中首次出现该字符的地址，否则返回NULL
    char * g;
    if(g =strchr("dsf",'s')!=NULL){
        printf("%c",*g);
    }



    return 0;
}