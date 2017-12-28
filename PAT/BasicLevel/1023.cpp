//1023 组个最小数
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

//按照价格从小到大排序

void print_vector(vector<int> a){
    vector<int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
        cout<<*it;
}

int main (void){
    vector<int>a;
    int i=0;
    int temp;
    do{
        cin>>temp;
        a.push_back(temp);
    }while(getchar()!='\n');

    //#include <algorithm> 默认<
    sort(a.begin(),a.end());
    vector<int>::iterator it=a.begin();
    if(*it==0){
        do{
            it++;
        }while(*it==0);
        swap(*a.begin(),*it);
        print_vector(a);
    }
    else
        print_vector(a);
    return 0;
}