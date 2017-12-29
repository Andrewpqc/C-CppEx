/**
 * 旧键盘2
 **/
#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
using namespace std;

bool exsit(char *p, size_t n, char ch){
    for (int i = 0; i < n; i++){
        if (ch == p[i])
            return true;
    }
    return false;
}

//判断字符ch是否可以打印出来
bool type_or_not(char *p, size_t n, char ch, bool f){
    if (isalpha(ch)){ //ch 是字母
        if (isupper(ch)){
            if (!f)
                return false;
            else{
                if (exsit(p, n, ch))
                    return false;
                else
                    return true;
            }
        }
        else if (islower(ch)){
            if (exsit(p, n, toupper(ch)))
                return false;
            else
                return true;
        }
    }
    else{ //非字母
        if (exsit(p, n, ch))
            return false;
        else
            return true;
    }
}
int main(void){
    char badkeys[42]; //存储输入的坏掉的键
    string s;         //存放需要打印的串
    bool f = true;
    char ch = getchar();
    int j;
    for (j = 0; ch != '\n'; j++, ch = getchar()){
        //将该字符存入数组
        badkeys[j] = ch;
        //判断是否上档键坏掉了
        if (ch == '+')
            f = false;
    }
    cin >> s;
    bool f2 = true;
    for (int i = 0; i < s.size(); i++){
        if (type_or_not(badkeys, j, s[i], f)){
            cout << s[i];
            f2 = false;
        }
    }
    if (f2)
        cout << endl;
    return 0;
}