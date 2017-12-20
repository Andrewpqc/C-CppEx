/**
 * printf()函数首先会把数据发送到buffer缓冲区
 * 然后将缓冲区里的数据发送到屏幕或文件，C标准规定
 * 当缓冲区满，遇到换行字符，或需要输入的时候，就会刷新
 * 缓冲区。
 */
#include <stdio.h>
#include <unistd.h>
int main (void){
    printf("why this not appered before sleep.\n");
    sleep(5);
    return 0;
}
/**
 *程序执行结束了之后也会刷新缓冲区 
 *　fflush()手动刷新缓冲区 
 */