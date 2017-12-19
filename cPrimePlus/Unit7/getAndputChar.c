#include <stdio.h>

int main(void){
    char ch;
    while ((ch = getchar()) != '\n'){
        if (ch == ' ')
            putchar(ch);
        else
            putchar(ch + 1);
    }
    putchar(ch);
    return 0;
}