/**
 * 编译时出现sqrt函数未定义：
 * /tmp/ccrsMi1D.o：在函数‘main’中：
 * assert.c:(.text+0x74)：对‘sqrt’未定义的引用
 * collect2: error: ld returned 1 exit status
 * 
 * 解决方法：
 * 编译的时候也要在指令后面加 -lm：
      gcc -o abc abc.c -lm
　　原因：缺少某个库，用 -l 参数将库加入。Linux的库命名是一致的, 一般为 libxxx.so, 或 libxxx.a, libxxx.la, 要链接某个库就用   -lxxx，去掉头 lib 及 "." 后面的 so, la, a 等即可。
　　常见的库链接方法为：数学库 -lm; posix 线程 -lpthread
 * 
 */ 


#define NDEBUG //禁用assert
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main (void){
    double x,y,z;

    while(scanf("%lf %lf",&x,&y)==2 && x!=0 && y!=0){
        z=x*x-y*y;
        assert(z>=0); 
        //如果断言返回false,会出现如下错误，为什么会出现核心已转储？？？？
        /*a.out: assert.c:27: main: Assertion `z>=0' failed.
        已放弃 (核心已转储)*/
        printf("%lf\n",sqrt(z));
    }
    return 0;
}

//sqrt(-1),返回的是啥?，%lf -nan 扯淡