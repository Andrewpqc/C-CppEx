#include <stdio.h>
#include <string.h>
#define N 20
#define L 20
#define M 10

struct wordstream{
    char w[N];
}word[L];

int main(void){
    int code[M];//存储码字流
    int i,k,t;
    int j;//词典中的下一个缀－符串序号
    int cW;//当前码字
    int pW;
    unsigned char C;//当前字符
    char p[20];//先前缀-符串

    //输入词典的初始值
    word[1].w[0]='A';
    word[2].w[0]='B';
    word[3].w[0]='C';
    j=4;
    //输入需要译码的码字流
    printf("\nPlease input the codestring number:");//输入码字流中码字的个数
    scanf("%d",&k);
    //依次输入码字流中的各个码字(每两个码字间用空格隔开)
    printf("\nPlease input the codestream:");
    for(i=0;i<k;i++){
        scanf("%d",(code+i));
    }
    printf("\nOutput the wordstream:");
    cW=code[0];//读入第一个码字
    printf("%s",word[cW].w);
    pW=cW;
    //循环运行，判断当前缀-符串是否在词典中
    for(i=1;i<k;i++){
        cW=code[i];
        if(cW<j){//当前缀符串在词典中的情况
            printf("%s",word[cW].w);//输出到字符流
            C=word[cW].w[0];//当前前缀－符串的第一个字符
            strcpy(p,(const char*)word[pW].w);
            t=strlen((const char *)p);//p+c
            p[t]=C;
            p[t+1]='\0';
            strcpy(word[j].w,(const char*)p);//添加到词典
            j+=1;
            pW=cW;
        }else{//当前缀-符串不在词典中的情况
            strcpy(p,(const char*)word[pW].w);//先前前缀－符串
            C=word[pW].w[0];//先前前缀－符串的第一个字符
            t=strlen((const char*)p);
            p[t]=C;
            p[t+1]='\0';
            strcpy(word[j].w,(const char*)p);
            printf("%s",p);
            j+=1;
            pW=cW;
        }
    }

    for(i=1;i<j;i++){
        printf("\nThe dictionary is %d : %s",i,word[i].w);
    printf("\n");

    }
}