/**
 * 挖掘机技术哪家强
 **/ 

#include <iostream>
using namespace std;
typedef unsigned long ul;
int main (void){
    ul school_num=0;
    int score=0;
    int N;
    cin>>N;
    int a[N]={0};//起始分数均为0
    for(int i=0;i<N;i++){
        cin>>school_num>>score;
        a[school_num-1]+=score;
    }
    int max=a[0];
    ul school=1;
    for(int j=1;j<N;j++){
        if(a[j]>max){
            max=a[j];
            school=j+1;
        }
    }
    cout<<school<<" "<<max;
    return 0;
}