/**
 * http://blog.csdn.net/shuaishuai80/article/details/6140979
 */ 
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int* a=(int*)malloc(100*sizeof(int));
    for(int i=0;i<100;i++){
        printf("%d\n",a[i]);
    }
    free(a);

    puts("--------------------------------");
    int* b=(int*)calloc(100,sizeof(int));
    for(int j=0;j<100;j++){
        printf("%d\n",b[j]);
    }
    free(b);
    return 0;
}