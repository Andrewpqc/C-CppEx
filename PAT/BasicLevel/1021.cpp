#include <iostream>
#include <cstring>
using namespace std;

int main (void){
    int b[10]={0};
    char a[1000];
    cin>>a;
    for(int i=0;i<strlen(a);i++){
        int temp=a[i]-'0';
        ++b[temp];
    }

    for(int j=0;j<10;j++){
        if(b[j]){
            cout<<j<<":"<<b[j]<<endl;
        }
    }
    return 0;
}