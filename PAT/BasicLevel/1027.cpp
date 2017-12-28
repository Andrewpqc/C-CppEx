/**
 * 一个稍显调皮的漏斗，整体倾斜，我也不晓得怎么办
 **/ 
#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int a;
    char ch;
    cin >> a >> ch;
    float b = sqrt((float)(a + 1) / 2);
    int c = ((int)b) * 2 - 1;
    int flag = 0;
    do{
        for (int j = 0; j < flag; j++){
            cout << ' ';
        }
        for (int i = 0; i < c; i++){
            cout << ch << ' ';
        }
        if (c != 1){
            cout << endl;
        }
        c = c - 2;
        flag++;
    } while (c > 0);

    do{
        for (int j = 0; j < flag; j++){
            cout << ' ';
        }
        for (int i = 0; i < c; i++){
            cout << ch << ' ';
        }
        cout << endl;
        c = c + 2;
        flag--;
    } while (c <= ((int)b) * 2 - 1);
    return 0;
}