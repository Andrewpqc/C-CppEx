#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int a, b;
    bool flag=false;;
    cin >> a >> b;
    int c = a + b;
    vector<char> v;
    if(c==0){
        cout<<0<<endl;
        return 0;
    }
    if(c<0){
        flag=true;
        c=-c;
    }
    while (c){
        int t = c % 10;
        v.push_back((char)(t + 48));
        c = c / 10;
    }
    size_t size = v.size();
    if(flag){
        cout<<"-";
    }
    for (int i = size - 1; i >= 0; i--){
        cout << v[i];
        if (i != 0 && i % 3 == 0){
            cout << ",";
        }
    }
    cout<<endl;
    return 0;
}