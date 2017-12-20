#include <stdio.h>
int main (void){
    const int A = 10;//read-only
    A=9;//报错
    return 0;
}