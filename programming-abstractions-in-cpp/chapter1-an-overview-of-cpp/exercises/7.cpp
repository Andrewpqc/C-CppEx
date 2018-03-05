#include <iostream>
using namespace std;

bool is_perfect(int);

int main(void){
    for (int i = 1; i <= 9999; i++){
        if (is_perfect(i)){
            cout << i << endl;
        }
    }
    return 0;
}

bool is_perfect(int n){
    if (n == 1)
        return false; //1要单独考虑
    int sum = 1;
    for (int i = 2; i * i <= n; i++){
        int remain = n % i;
        if (!remain){
            int result = n / i;
            sum += (i + result);
        }
    }
    return (sum == n) ? true : false;
}