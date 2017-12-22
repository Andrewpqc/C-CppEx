/**
 * stdio.h sprintf
 * 将格式化数据写入到字符串中
 */
#include <stdio.h>
int main (void){
    char a[100];
    int i=2;
    sprintf(a,"this is a %d hh ",i);
    puts(a);
    return 0;
}

