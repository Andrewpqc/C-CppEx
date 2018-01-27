#include <iostream>
#include <string>
using namespace std;

int main (void){
    string right_pwd;
    int count;
    cin>>right_pwd>>count;
    string temp;
    int flag=0;
    do{
        flag++;
        cin>>temp;
        if(flag<=3){
            if(temp!=right_pwd){
            cout<<"Wrong password: "<<temp<<endl;
            }else{
                cout<<"Welcome in"<<endl;
                return 0;
            }
        }else{
            cout<<"Account locked"<<endl;
            return 0;
        }
        
    }while(temp!="#");
    return 0;
}