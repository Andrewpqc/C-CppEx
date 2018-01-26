/**
 * 找规律 部分正确
 **/
#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
    int count;
    cin >> count;
    float arr[count];
    float sum = 0.0;
    for (int i = 0; i < count; i++)
        cin >> arr[i];
    for (int i = 0; i < count; i++)
        sum += arr[i] * (count - i) * (i + 1);
    cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
    return 0;
}