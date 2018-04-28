/**
 * lzw算法
 */ 

#include <stdio.h>
#include <string.h>


#define N 20　//词典中存储的短语字符串的最大长度
#define L 20　//词典中的短语的最大个数

struct wordstream{
    char w[N];
} word[L];

int main(void){
    int code;//输出码字
    int i,k;
    int j,t;
    int flag;
    char C;//当前字符
    char input_str[30];//待压缩字符串
    int input_strlen;//待压缩字符串长度

    char p[20];//前缀p
    p[0]='\0';//前缀p置空
    printf("\n Please input the string:\n");
    gets(input_str);
    word[1].w[0]=input_str[0];//求单字符根

    j=2;
    for(i=1;input_str[i]!='\0';i++){
        for(k=1;k<j;k++){
            if(input_str[i]==word[k].w[0]) break;
        }
        if(k==j){
            word[j].w[0]=input_str[i];
            j++;
        }
    }
    
    input_strlen=strlen(input_str);
    printf("The result of LZW coding is:\n");
    for(i=0;i<input_strlen;i++){
        for(k=1;k<j;k++){//找出前缀p对应的码字
            if(strcmp(p,word[k].w==0)){
                code=k;//前缀p对应的码字
                break;
            }
            C=input_str[i];//当前字符
            t=strlen((const char*)p);
            p[t]=C;
            p[t+1]='\0';

            flag=0;//P+C是否在词典中的判断标志
            for(k=1;k<j;k++){
                if(strcmp(p,word[k].w)==0){
                    flag=1;
                    break;
                }
                if(flag==0){//p+c不在词典中
                    printf("%d ",code);
                    strcpy(word[j].w,(const char*)p);//将p+c加入词典中
                    j++;//下一个词典短语序号加１
                    p[0]=C;
                    p[1]='\0';
                }
            }

            if(p[0]!='\0')
                for(k=1;k<j;k++){
                    if(strcmp(p,word[k].w)==0){
                        printf("%d ",k);
                        break;
                    }
            printf("\n the dictionary is:\n");
            for(k=1;k<j;k++){
                printf("%d:%s\n",k,word[k].w);
            printf("this is over!\n");
            }
                }

        }
    }

    return 0;
}