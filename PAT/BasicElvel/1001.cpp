/**
 * 害死人不偿命的3n+1猜想1001
 */
#include <iostream>
using namespace std;
int main(void){
    int a, flag = 0;
    cin >> a;
    while (a != 1){
        ++flag;
        if (a % 2 == 0){
            a /= 2;
        }
        else{
            a = (3 * a + 1) / 2;
        }
    }
    cout << flag << endl;
    return 0;
}