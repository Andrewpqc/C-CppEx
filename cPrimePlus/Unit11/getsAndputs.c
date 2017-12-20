#include <stdio.h>

int main (void){
    char a[100];
    // FILE *fp=fopen("strstart.c","r");
    //从标准输入读取读取最多９个字符，或者遇到换行符，fgets读到换行符会将其存储在字符串中    
    fgets(a,10,stdin);
    fputs(a,stdout);
    // fclose(fp);


    return 0;
}