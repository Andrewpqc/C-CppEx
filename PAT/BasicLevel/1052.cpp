#include <iostream>
#include <cstdio>
using namespace std;
#define MAXLINE 60
#define ON 1
#define OFF 0
int getin(char *focus[],char save[]); //读入表情，构造指针数组，以及返回表情个数
void printexp(char *first[], int target); 

int main(){
    int lh, le, m, re, rh; //分别为左手，左眼，嘴，右手，右眼 
    int eyemax, handmax, monthmax; //最大序号 
    char *hand[10],*eye[10],*month[10]; //指针数组 
    char handstore[MAXLINE],eyestore[MAXLINE],monthstore[MAXLINE]; //字符数组

    handmax = getin(hand,handstore);
    eyemax = getin(eye,eyestore);
    monthmax = getin(month,monthstore);

    int repeat,ri;
    scanf("%d",&repeat);
    for(ri=1;ri<=repeat;ri++){
        scanf("%d%d%d%d%d",&lh, &le, &m, &re, &rh);
        if(lh <= handmax && rh <= handmax && 
           le <= eyemax && re <= eyemax && 
           m <= monthmax 
           && lh >= 1 && rh >= 1 && 
           le >= 1 && re >= 1 && 
           m >= 1) // 这里注意不仅要考虑给出序号过大，也要考虑过小的情况 
           {
            printexp(hand, lh);
            printf("(");
            printexp(eye, le);
            printexp(month, m);
            printexp(eye, re);
            printf(")");
            printexp(hand, rh);
            printf("\n");
           }  // 按格式输出 
        else
            printf("Are you kidding me? @\\/@\n");
    }

}

int getin(char *focus[],char save[]){
    int state; 
    char *p,ch;
    p = save;
    int i = 0;
    focus[0]=p;
    while((ch = getchar()) != '\n'){
        if(ch == '[')
            state = ON; //开始读入字符 
        else if(ch == ']' && state == ON){
            *p++ = 0; //每个表情末尾加上结束符号 
            focus[++i] = p; //构造指针，使其指向表情开头 
            state = OFF;
        }
        else if(state == ON)
            *p++ = ch;
    }
    return i;

}

void printexp(char *first[], int target){
    printf("%s", first[target-1]);
}