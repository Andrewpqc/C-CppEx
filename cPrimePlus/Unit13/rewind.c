/**
 * fprintf()
 * fscanf()
 * rewind()
 */ 
#include <stdio.h>
#include <stdlib.h>

int main (void){
    FILE* fin_p;
    char ch;
    char words[201];
    if((fin_p=fopen("readAndcount.c","r"))==NULL){
        fprintf(stderr,"open %s error!","readAndcount.c");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fin_p))!=EOF){
        if(ch!='|')
            putc(ch,stdout);
        else
        rewind(fin_p);//回到文件开头
    }

//上面的程序永远也不会停止
    return 0;
}