static unsigned long seed=1; //种子

unsigned int my_rand(void){
    //伪随机数魔术公式
    seed=seed*1103515245+12345;
    return (unsigned int)(seed/65536)%32768;
}

void reseed(unsigned long a){
    //重置种子
    seed=a;
}

#include <time.h>

void autoreseed(void){
    //根据系统时间自动重置种子
    seed=(unsigned long)time(0);
    printf("seed:%u\n",seed);
}