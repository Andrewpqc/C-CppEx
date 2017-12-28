#include <iostream>
#include <climits>
using namespace std;
typedef unsigned long long ull;

int main (void){
    int c[32]={0};
    ull a,b,sum;
    int D;
    cin>>a>>b>>D;
    sum=a+b;
    int flag=0;
    while(sum){
        c[flag++]=sum%D;
        sum=sum/D;
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    for(int i=flag-1;i>=0;i--){
        cout<<c[i];
    }
    return 0;
}