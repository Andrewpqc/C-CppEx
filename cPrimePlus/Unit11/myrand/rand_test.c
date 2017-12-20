#include <stdio.h>
#include "rand.c"
// extern unsigned int my_rand(void);

int main (void){
    unsigned long seed;
    puts("Please  give me your seed:");
    while((scanf("%u",&seed))==1){
        reseed(seed);
    for(int i=0;i<5;i++){
        printf("%u\n",my_rand());
    }
    puts("another:");
    }
    return 0;
}