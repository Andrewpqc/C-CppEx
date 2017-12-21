/**
 * 刷新缓冲区
 */ 

/**
 * 如果没有手动刷新缓冲区
 * 则只有在文件关闭的时候才能
 * 将要写入放入东西写入缓冲区
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void){
    FILE* fp=fopen("aaa.txt","a");
    fprintf(fp,"this is nothing %s here!","shabi");
    sleep(5);
    puts("sleep over!");
    // fflush(fp);
    sleep(5);
    puts("sleep over 2");
    fclose(fp);
    return 0;
}