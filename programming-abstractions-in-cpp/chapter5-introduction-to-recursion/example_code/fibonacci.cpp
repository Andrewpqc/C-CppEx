#include <iostream>
using namespace std;

int fib_recursion(int n){
    if (n <= 2)
        return n-1;
    else{
        return fib_recursion(n - 1) + fib_recursion(n - 2);
    }
}

int fib_none_recursion(int n, int t1 = 0, int t2 = 1){
    if (n == 1)
        return t1;
    if (n == 2)
        return t2;
    int t;
    for (int i = 0; i < n - 2; i++){
        t = t1 + t2;
        t1 = t2;
        t2 = t;
    }
    return t;
}
int main(void){
    cout << fib_none_recursion(5) << endl;
    cout << fib_recursion(5) << endl;
    return 0;
}

