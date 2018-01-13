#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void){
    long duiwu[1000]={0};
    int count;
    cin>>count;
    string s;
    long score;
    for(int i=0;i<count;i++){
        cin>>s>>score;
        string s2=s.substr(0,s.find("-"));
        duiwu[atoi(s2.c_str())-1]+=score;
    }
    
    long max=duiwu[0];
    int bianhao=0;
    for(int i=1;i<1000;i++)
        if(max<duiwu[i]){
            max=duiwu[i];
            bianhao=i;
        }
    cout<<bianhao+1<<" "<<max<<endl;
    return 0;
}