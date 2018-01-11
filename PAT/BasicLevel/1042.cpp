/**
 * 找出字符串中出现频率最高的字符
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main(void){
    char s[1001];
    int a[26] = {0};
    gets(s);
    for (int i = 0; i < strlen(s); i++){
        if (isalpha(s[i])){
            int temp = tolower(s[i]);
            a[temp - 97]++;
        }
    }
    int max = a[0];
    int max_index = 0;
    for (int index = 1; index < 26; index++){
        if (a[index] > max){
            max = a[index];
            max_index = index;
        }
    }
    cout << (char)(max_index + 97) << " " << max << endl;
    return 0;
}