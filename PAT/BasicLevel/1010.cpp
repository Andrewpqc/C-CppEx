/**
 * 1010 一元多项式求导,为什么答案错误，受不了了
 */ 
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> vector1;
    vector<int> vector2;
    //注意下面这个循环，连续获取用户输入并且判断用户是否输入换行符
    do{
        int t;
        cin>>t;
        vector1.push_back(t);
    }while(cin.get()!='\n');

    for(int i=0;i<vector1.size();i+=2){
        if(vector1[1+i]){
            int n=vector1[i]*vector1[i+1];
            vector2.push_back(n);
            int m=vector1[i+1]-1;
            vector2.push_back(m);
        }
    }
    
    for(int i=0;i<vector2.size();i++){
        cout<<vector2[i]<<" ";
    }
    cout<<"\b";
    return 0;
}