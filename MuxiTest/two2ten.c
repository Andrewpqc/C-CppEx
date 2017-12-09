/**
 * 将一个小于10000000的二进制数转化为十进制数
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int transform(int num){
    int flag = 0, sum = 0, bit, newNum, i;
    int bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    bit = num % 10;
    if (bit > 1){
        printf("Sorry,your number is not a Binary number\n");
        exit(0);
    }
    newNum = num / 10;
    bits[0] = bit;
    while (newNum){
        bit = newNum % 10;
        newNum = newNum / 10;
        bits[++flag] = bit;
        if (bit > 1){
            printf("Sorry,your number is not a Binary number\n");
            exit(0);
        }
        if (flag >= 8){
            printf("Sorry,We can't transform a number bigger than 10000000!\n");
            exit(0);
        }
    }

    for (i = 0; i < 8; i++)
        sum += bits[i] * pow(2, i);

    return sum;
}

int main(void){
    long num;
    printf("please enter your binary number:");
    scanf("%ld", &num);
    printf("%d\n", transform(num));
    return 0;
}
