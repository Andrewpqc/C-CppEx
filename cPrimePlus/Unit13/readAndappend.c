/**
 * 将源文件的内容追加到目标文件中
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 5000

void append(FILE* s,FILE* d){
    /*methods 1*/
    // char ch;
    // while((ch=getc(s))!=EOF){
    //     putc(ch,d);
    // }

    /* methods 2 */
    size_t bytes;
    static char temp [BUFSIZE];//只分配一次，这里充当缓冲区
    while((bytes=fread(temp,sizeof(char),BUFSIZE,s))>0)
        fwrite(temp,sizeof(char),bytes,d);  
}


int main (void){
    FILE* df;//目标文件句柄
    FILE* sf;//源文件句柄
    char dest[30];//目标文件名
    char source[30];//源文件名
    printf("Enter the destination filename:");
    scanf("%s",dest);

    //打开目标文件
    if((df=fopen(dest,"a+"))==NULL){
        fprintf(stderr,"Open destination %s error!\n",dest);
        exit(EXIT_FAILURE);
    }

    //为目标文件流创建缓冲区
    if(setvbuf(df,NULL,_IOFBF,BUFSIZE)!=0){
        //缓冲区创建成功，返回０，否则返回非零值
        fprintf(stderr,"Create buffer for output stream error!");
        exit(EXIT_FAILURE);

    }

    printf("Enter your first source file name(empty line to quit):");
    while(scanf("%s",source)==1 && source[0]!='\0'){
        if(strcmp(dest,source)==0){
            fprintf(stderr,"Can't append %s to itself!　We have passed it for you.",source);
            printf("Enter your next source file name(empty line to quit):");
            continue;//跳过自身
        }
        if((sf=fopen(source,"r"))==NULL){
            fprintf(stderr,"Open source file %s error!",source);
            exit(EXIT_FAILURE);
        }

        //为源文件流创建缓冲区
        if(setvbuf(sf,NULL,_IOFBF,BUFSIZE)!=0){
            fprintf(stderr,"Create buffer for input stream error!");
            exit(EXIT_FAILURE);
        }
        
        append(sf,df);
        
        fclose(sf);

        if(ferror(sf)!=0){
            fprintf(stderr,"error when read %s !",source);
            exit(EXIT_FAILURE);
        }

        if(ferror(df)!=0){
            fprintf(stderr,"error when write %s !",dest);
            exit(EXIT_FAILURE);
        }
        printf("successfully append %s to %s !\n",source,dest);
        printf("Enter your next source file name(empty line to quit):");
    }

    return 0;
}


