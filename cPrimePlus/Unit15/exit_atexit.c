/**
 * exit() and atexit()
 **/ 
#include <stdio.h>
#include <stdlib.h>
void func1(void){
    puts("I am func1");
}
void func2(void){
    puts("I am func2");
}

int main (void){
    int a;
    atexit(func1);
    if(scanf("%d",&a) != 1){
        atexit(func2);
        exit(EXIT_FAILURE);
    }
    printf("%d\n",a);
    return 0;
}