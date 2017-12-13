#include <iostream>
using namespace std;

//设计了一个函数，它的参数b给了默认值0,这时函数参数缺省的情况
int add (int a,int b=0){
    return a+b;
}

//重载了上面的函数
float add(float a,float b){
    return a+b;
}
int main (void){
    cout<<add(1)<<endl;
    int a,b;
    cin >> a >> b;
    cout<<add(a,b)<<endl;
    float c,d;
    cin>>c>>d;
    cout<<add(c,d)<<endl;
    return 0;
}