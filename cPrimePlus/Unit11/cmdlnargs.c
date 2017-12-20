/**
 *命令行参数 
 */ 

#include <stdio.h>
int main (int argc,char** argv){
    printf("%d\n",argc);
    for(int i=1;i<argc;i++){
        puts(argv[i]);
    }
   
    return 0;
}