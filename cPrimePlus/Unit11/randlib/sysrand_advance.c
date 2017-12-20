#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void){
    for(int i=0;i<10;i++){
        srand(time(NULL)); //利用系统时间重置种子
        printf("%d ",rand()%10+1);
    }
    return 0;
}