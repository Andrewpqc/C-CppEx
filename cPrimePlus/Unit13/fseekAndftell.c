/**fseek()
 * fseek函数需要三个参数，fp,offest,mode
 * fp:所操作的文件
 * offset:偏移量　0:不一动，正数:前移，负数:后移，必须是long类型的值，以字节数为单位
 * mode:SEEK_SET,SEEK_CUR,SEEK_END
 * 上面的三种模式分别对应文件的开始，当前位置，文件的结尾
 * 如果一切正确seek()返回０，否则返回-1
 * 
 * 
 * ftell()
 * ftell()函数返回的是当前位置，返回是一个long类型的数字
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
    FILE* fp=fopen("readAndcount.c","r");
    //定位到文件末尾的倒数第200个字符
    fseek(fp,-200L,SEEK_END);
    //获取并打印当前字符
    char ch=getc(fp);
    putchar(ch);
    //获取当前的位置
    printf("\n%ld\n",ftell(fp));//ftell返回long类型
    return 0;
}