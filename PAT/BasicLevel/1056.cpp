/**
 * 组合数的和
 **/
#include <iostream>
using namespace std;

int main(void){
    int count;
    int a[count];
    cin >> count;
    for (int i = 0; i < count; i++){
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < count - 1; i++){
        for (int j = i + 1; j < count; j++){
            sum += (10 * a[i] + a[j] + 10 * a[j] + a[i]);
        }
    }
    cout << sum << endl;
    return 0;
}