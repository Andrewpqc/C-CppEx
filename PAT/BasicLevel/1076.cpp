#include <iostream>
#include <string>
using namespace std;

int main (void){
    size_t count;
    cin>>count;
    string tmp;
    bool flag;
    for(int i=0;i<count;i++){
        flag=false;
        for(int i=0;i<4;i++){
            cin>>tmp;
            if(!flag){
                size_t pos=tmp.find('-');
                char choice=tmp.substr(0,pos)[0];
                char tf=tmp.substr(pos+1)[0];
                if(tf=='T'){
                    flag=true;
                    switch(choice){
                        case 'A':cout<<1;break;
                        case 'B':cout<<2;break;
                        case 'C':cout<<3;break;
                        case 'D':cout<<4;break;
                    }
            }
            }
        }
    }
    return 0;
}