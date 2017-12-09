/**
 *找100以内的素数
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void){
    int i, j, flag;
    //２单独处理
    printf("%d ", 2);
    for (i = 3; i < 101; i++){
        flag = 0;
        for (j = 2; j * j <= i; j++){
            if (i % j == 0){
                ++flag;
            }
        }
        if (flag == 0){
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
