/**
 * 部分正确
 **/ 
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    char result[101];
    char a[101];
    char b[101];
    cin >> a >> b;
    //c,d是反转之后的内容
    int c[101];
    int d[101];
    size_t a_len = strlen(a);
    size_t b_len = strlen(b);
    for (int i = a_len - 1; i >= 0; i--)
        c[a_len - i - 1] = a[i] - '0';
    for (int j = b_len - 1; j >= 0; j--)
        d[b_len - j - 1] = b[j] - '0';

    int i = 0;
    for (; i < b_len && i < a_len; i++){
        if (i % 2 == 0){ //奇数位
            int t = (c[i] + d[i]) % 13;
            if (t < 10){
                result[i] = t + '0';
            }
            else if (t == 10){
                result[i] = 'J';
            }
            else if (t == 11){
                result[i] = 'Q';
            }
            else if (t == 12){
                result[i] = 'K';
            }
        }
        else{
            int t = d[i] - c[i];
            if (t < 0)
                t += 10;
            result[i] = t + '0';
        }
    }

    if (i == a_len){
        for (int j = a_len; j < b_len; j++)
            result[j] = d[j] + '0';
    }

    for (int j = b_len - 1; j >= 0; j--)
        cout << result[j];

    return 0;
}