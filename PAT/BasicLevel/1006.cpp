/**
 * 1006 换个格式输出整数　终于又通过了一道题啊，感动到哭！！
 */ 
#include <iostream>
using namespace std;
int main(void){
    int bits[3]={-1,-1,-1};
    int num,bit,newNum,flag=0;
    cin>>num;
    bit = num % 10;
    newNum = num / 10;
    bits[0] = bit;
    while (newNum){
        bit = newNum % 10;
        newNum = newNum / 10;
        bits[++flag] = bit;
    }
    //123 flag=2
    //flag 0 1 2
    if(flag==2){
        for(int i=0;i<bits[2];i++)
            cout<<"B";
        for(int i=0;i<bits[1];i++)
            cout<<"S";
        for(int i=0;i<bits[0];i++)
            cout<<i+1;
    }
    else if(flag==1){
        for(int i=0;i<bits[1];i++)
            cout<<"S";
        for(int i=0;i<bits[0];i++)
            cout<<i+1;
    }
    else if (flag==0){
        for(int i=0;i<bits[0];i++)
            cout<<i+1;
    }
    
    return 0;
}