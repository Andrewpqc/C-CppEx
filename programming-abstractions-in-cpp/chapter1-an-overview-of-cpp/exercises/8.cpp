#include <iostream>
#include <vector>
using namespace std;
//先找出小于输入的数的所有指数
int main (void){
    int num;
    vector<int> prime_vec;
    cout<<"Enter number to be factored:";
    cin>>num;
    for(int i=2;i<=num;i++){
        bool flag = true;
        for(int j = 2; j * j < i; j++){
            if(i % j == 0){//除断了,说明不是素数
                flag = false;
                break;
            }     
        }
        if(!flag){
            cout<<i<<" ";
        }
    }
    return 0;
}