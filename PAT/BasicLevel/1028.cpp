/**
 * 人口普查　1028 部分正确
 **/ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define Y_NOW 2014
#define M_NOW 9
#define D_NOW 6
using namespace std;

typedef struct Node{
    string name;
    int year;
    int month;
    int day;
}Person;

bool compare_condition (Person i,Person j){ 
    if(i.year!=j.year)
        return (i.year<j.year);
    else if(i.month!=j.month)
        return (i.month<j.month);
    else 
        return (i.day<j.day);
} 


int main (void){
    string name;
    string data;
    int N;
    cin>>N;
    
    vector <Person> pvt;
    for(int i=0;i<N;i++){
        cin>>name>>data;
        int y,m,d;
        y=atoi(data.substr(0,4).c_str());
        m=atoi(data.substr(5,7).c_str());
        d=atoi(data.substr(8.10).c_str());
        
        if(y>Y_NOW || y<Y_NOW-200)
            continue;
        else if(y==Y_NOW){
            if(m>M_NOW){
                continue;
            }
            else if(m==M_NOW){
                if(d>D_NOW)
                    continue;
            }
        }
        else if(y==Y_NOW-200){
            if(m<M_NOW){
                continue;
            }
            else if(m==M_NOW){
                if(d<D_NOW)
                    continue;
            }
        }

        Person ptemp;
        ptemp.name=name;
        ptemp.year=y;
        ptemp.month=m;
        ptemp.day=d;
        pvt.push_back(ptemp);
    }
    sort(pvt.begin(),pvt.end(),compare_condition);
    int sum=pvt.size();
    cout<<sum<<" "<<pvt[0].name<<" "<<pvt[sum-1].name<<endl;
    return 0;
}