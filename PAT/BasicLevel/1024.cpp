/**
 * 1024 正则表达式 又是部分正确，无语的一笔
 * 
 **/ 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main (void){
    string result="";//存放结果
    bool zf1;//数字正负
    bool zf2;//指数正负
    string s;//接收输入的字符串
    cin>>s;
    string n="";//接收数字
    string m="";//接收指数
    //数字的正负
    zf1=(s.at(0)=='+')?true:false;
    int i;
    for(i=1;(s.at(i))!='E';i++){
        if(s.at(i)=='.')
            continue;
        else
            n+=s.at(i);
    }
    //指数的正负
    zf2=(s.at(i+1)=='+')?true:false;
    
    //指数的大小
    for(int j=i+2;j<s.length();j++){
        m+=s.at(j);
    }
    int zhishu=atoi(m.c_str());
    //指数为正
    if(zf2){
        if(n.length()==(zhishu+1)){
            //当前结果就为n
            result=n;
        }else if(n.length()<(zhishu+1)){
            //需要在末尾添加0
            result=n;
            for(int i=0;i<((zhishu+1)-n.length());i++)
                result+='0';
        }else{
            //需要向左移动小数点
            string sub1=n.substr(0,zhishu+1);
            cout<<sub1<<endl;
            string sub2=n.substr(zhishu+1,n.length()-zhishu+2);
            cout<<sub2<<endl;
            result=sub1+'.'+sub2;
        }
    }
    //指数为负
    else{
        result="0.";
        for(int i=0;i<zhishu-1;i++)
            result+='0';
        result+=n;
    }

    if(!zf1)
        result='-'+result;

    cout<<result<<endl;
    return 0;
}