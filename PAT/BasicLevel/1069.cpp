/**
 * 感觉需要使用递归
 **/ 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_in_or_not(string temp,vector<string>& l){
    vector<string>::iterator it;
    for(it=l.begin();it!=l.end();it++){
        if(*it==temp){
            return true;//list中已经存在temp了
        }
    }
    return false;
}


int main (void){
    int M,N,S;
    cin>>M>>N>>S;
    vector<string> v;
    vector<string> v2;
    string temp;
    for(int i=0;i<M;i++){
        cin>>temp;
        v2.push_back(temp);
    }

    
    
    for(int i=0,flag2=0;i<M;i++,flag2++){
        if(i==S-1){//开始中奖的人
            v.push_back(v[i]);
            flag2=0;
        }else if(i>=S){
            if(flag2==N){
                if(is_in_or_not(v[i],v)){
                    //已经存在
                        flag2=-1;
                        //讨论下一个
                }else{
                    v.push_back(v[i]);
                    flag2=0;
                }
            }
        }   
    }

    if(v.size()==0){
        cout<<"Keep going..."<<endl;
    }else{
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
    }
    return 0;
}