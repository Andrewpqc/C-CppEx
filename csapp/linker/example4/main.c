#include <stdio.h>
#include "vector.h"

int main (void){
    int x[2]={1,2};
    int y[2]={3,4};
    int z[2];
    int m[2];
    addvec(x,y,z,2);
    multvec(x,y,m,2);
    printf("add result:%d, %d\n",z[0],z[1]);
    printf("mult result:%d, %d\n",m[0],m[1]);
    return 0;
}