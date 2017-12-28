/**
 * 1029 旧键盘
 **/ 

#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main(void){
    vector<char> badKey; //存储换掉的键
    char s1[80];         //敲击的字符
    char s2[80];         //实际输入的字符
    cin >> s1 >> s2;
    //做一个简单的处理
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    for (int i = 0; i < s1_len; i++){
        if (isalpha(s1[i]))
            s1[i] = toupper(s1[i]);
    }
    for (int i = 0; i < s2_len; i++){
        if (isalpha(s2[i]))
            s2[i] = toupper(s2[i]);
    }

    int i = 0, j = 0;
    int minLen = (s1_len < s2_len) ? s1_len : s2_len;
    do{
        if (s1[i] != s2[j]){
            vector<char>::iterator it = find(badKey.begin(), badKey.end(), s1[i]);
            if (it == badKey.end()) //没找到
                badKey.push_back(s1[i]);
            i++;
        }
        else{
            ++i;
            ++j;
        }
    } while (i < s1_len && j < s2_len);

    vector<char>::iterator it;
    for (it = badKey.begin(); it != badKey.end(); it++){
        cout << *it;
    }
    return 0;
}