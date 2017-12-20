/**
 * exit()关闭所有打开的文件
 * 并且退出程序，正常结束传递０，
 * 非正常结束传递非零值，也可以传递stdlib.h中
 * 定义的宏EXIT_FAILURE,EXIT_SUCCESS9
 */ 
|

#include <stdio.h>
#include <stdlib.h>
int main (int argc,char* argv[]){
    int count=0;
    char ch;
    FILE* fp;
    if(argc!=2){
        printf("%s <filename>",argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp=fopen(argv[1],"r"))==NULL){
        puts("Can't open this file");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF){
        putc(ch,stdout);
        ++count;
    }
    fclose(fp);
    printf("There are %d charactors in %s",count,argv[1]);
    return 0;
}





