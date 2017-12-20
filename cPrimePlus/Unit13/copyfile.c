#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc,char * argv []){
    char ch;
    char newfilename[100];
    FILE* fin_p;
    FILE* fout_p;
    if (argc!=2){
        printf("Usage: %s <filename>\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fin_p=fopen(argv[1],"r"))==NULL){
        printf("Open %s error!\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    strcpy(newfilename,argv[1]);
    strcat(newfilename,".brk");
    if((fout_p=fopen(newfilename,"w"))==NULL){
        printf("Open %s error!",newfilename);
        exit(EXIT_FAILURE);
    }

    while((ch=getc(fin_p))!=EOF){
        putc(ch,fout_p);
    }
    
    //文件关闭成功则返回0
    if(fclose(fin_p)!=0 || fclose(fout_p)!=0){
        puts("Close file error!");
        exit(EXIT_FAILURE);
    }
    return 0;
}