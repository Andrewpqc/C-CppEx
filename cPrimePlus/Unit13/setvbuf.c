/**
 * int setvbuf(FILE* restrict fp,char* restrict buf,int mode,size_t size);
 */ 

#include <stdio.h>
#include <stdlib.h>

int main (void){

    char a[1];
    char ch;
    if((setvbuf(stdin,NULL,_IONBF,1))==0&& (setvbuf(stdout,NULL,_IONBF,1))==0){
         while((ch = getchar())!=EOF){
             putchar(ch);
         }
    }
    return 0;
}