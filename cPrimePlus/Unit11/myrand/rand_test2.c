#include <stdio.h>
#include "rand.c"

int main (void){
    for(int i=0;i<1000000;i++){
        autoreseed();
        printf("%u\n",my_rand());
    }


    return 0;
}