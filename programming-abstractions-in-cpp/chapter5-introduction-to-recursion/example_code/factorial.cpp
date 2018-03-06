#include <iostream>
using namespace std;
int fact(int);
int fact_recursion(int);

int main(void){
    cout << fact(3) << endl;
    cout << fact_recursion(3) << endl;
}

int fact(int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int fact_recursion(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * fact_recursion(n - 1);
    }
}