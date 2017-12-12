/**
 * 1009 说反话　什么，部分正确？受不了了啊，这都没通过，这是要闹那般？
 */ 

#include <iostream>
#include <cstring>
using namespace std;
int main (void){
    char str[80];
    cin.getline(str,80);
    int length=strlen(str);
    for(int i=length;i>0;i--){
        cout<<str[i-1];
    }
    return 0;
}