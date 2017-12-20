#include <stdio.h>

int main (void){
    long a;
    // \b光标回退，我的机子上，回退光标没有擦除前面的内容
    printf("$_______\b\b\b\b\b\b\b");
    scanf("%ld",&a);
    printf("\t%ld",a);
    //\r　光标回到当前所在行的开头，在我的系统上，它会直接擦除当前行所有内容
    printf("\roh!");
    return 0;
}

