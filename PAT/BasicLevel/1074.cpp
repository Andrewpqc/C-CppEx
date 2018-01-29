/**
 * 宇宙无敌加法器
 **/ 
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct data{
    int remain;
    int jinwei;
};

struct data d;

void parse(int a,int b,int x){
    int sum=a+b;
    if(sum>=x){
        d.jinwei=sum/x;
        d.remain=sum%x;
    }else{
        d.jinwei=0;
        d.remain=sum;
    }
}

int main (void){
    string table,num1,num2;
    cin>>table>>num1>>num2;
    size_t table_len=table.size();
    size_t num1_len=num1.size();
    size_t num2_len=num2.size();
    size_t max=table_len;
    if(num1_len>max)
        max=num1_len;
    if(num2_len>max)
        max=num2_len;
    int table_arr_reverse[max]={10};
    int num1_arr_reverse[max]={0};
    int num2_arr_reverse[max]={0};
    vector<int> result;
    for(int i=table_len-1;i>=0;i--){
        if(table.at(i)=='0'){
            num1_arr_reverse[table_len-i-1]=10;
        }else{
            num1_arr_reverse[table_len-i-1]=(int)(table.at(i)-'0');
        }
    }
    for(int i=num1_len-1;i>=0;i--){
        num1_arr_reverse[num1_len-i-1]=(int)(num1.at(i)-'0');
    }
    for(int i=num2_len-1;i>=0;i--){
        num2_arr_reverse[num2_len-i-1]=(int)(num2.at(i)-'0');
    }
    
    int temp=0;
    // struct data tmp_data;
    cout<<max<<endl;
    for(int i=0;i<max;i++){
        cout<<temp<<endl;
        parse(num1_arr_reverse[i],num2_arr_reverse[i],table_arr_reverse[i]);
        result.push_back(d.remain+temp);
        temp=d.jinwei;
    }
    
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i];
    }



    return 0;
}