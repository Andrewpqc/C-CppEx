//相互递归,感觉很神奇啊
#include <iostream>
using namespace std;
bool isEven(int);
bool isOdd(int);

//偶数
bool isEven(int n){
    if(n==0)
        return true;
    else{
        return isOdd(n-1);
    }
}

bool isOdd(int n){
    return !isEven(n);
}

int main (void){
    cout<<isEven(2)<<endl;
    cout<<isEven(0)<<endl;
    cout<<isEven(1)<<endl;
    return 0;
}