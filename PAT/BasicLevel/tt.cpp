#include <iostream>
#include <vector>
using namespace std;

int main (void){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.erase(v.begin());
    v.erase(v.end()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }




    return 0;
}