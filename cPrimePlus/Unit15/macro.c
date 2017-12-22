/**
 * 预定义宏
 * 
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if __STDC_VERSION__ != 201112L
#error Not C11
int main (void){

    // printf("%s\n",__DATE__);
    // printf("%s",__FILE__);
    // printf("%s",__LINE__);
    // printf("%s",__STDC__);
   


    return 0;
}
#endif