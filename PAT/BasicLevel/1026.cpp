/**
 * 程序运行时间　１０２６
 **/ 

#include <iostream>
using namespace std;
#define CLK_TCK 100
typedef unsigned long long ull;
int main (void){
    ull a,b,c;
    cin>>a>>b;
    c=b-a;
    float s1=(float)c/CLK_TCK;//以秒为单位的时间
    ull s2=(ull)s1;//上述s1的整数部分
    float s3=s1-s2;//s1的小数部分
    //四舍五入
    if(s3>=0.5)
        s2+=1;
    int h,m,s;
    h=s2/3600;
    m=(s2-h*3600)/60;
    s=s2-h*3600-m*60;
    if(h<10)
        cout<<'0'<<h<<":";
    else
        cout<<h<<":";

    if(m<10)
        cout<<'0'<<m<<":";
    else
        cout<<m<<":";
    
    if(s<10)
        cout<<"0"<<s<<endl;
    else
        cout<<s<<endl;
     
    return 0;
} 