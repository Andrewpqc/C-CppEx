#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
int main (void){
    int M,N,lower_edge,high_edge,replace;
    vector<string> v;
    cin>>M>>N>>lower_edge>>high_edge>>replace;
    string temp;
    int tmp;
    for(int i=0;i<M*N;i++){
        cin>>temp;
        tmp=atoi(temp.c_str());
        if(lower_edge<=tmp&&tmp<=high_edge){
            v.push_back("000");
        }else if(temp.size()==1){
            v.push_back("00"+temp);
        }else if(temp.size()==2){
            v.push_back("0"+temp);
        }else{
            v.push_back(temp);
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        if((i+1)%N==0){
            cout<<'\b'<<endl;
        }
    }
    return 0;
}