/**
 * 字符串的压缩与解压,下面的版本中解压缩存在问题，不支持大于９个以上的相同字符
 * 暂时还没有好的解决办法。本题目有问题，例如对"234ZA"解压缩有多种情况。
 * 33ZZZZA
 * 23个４,一个Z,一个A
 * 234个Z,一个A
 **/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void){
    char F;
    cin >> F;
    getchar(); //处理换行符，以免被下面的程序使用
    if (F == 'C'){
        int flag = 1;
        char t;
        char temp = getchar(); //拿到第一个字符
        while (true){
            t = getchar();
            if (t == temp){
                ++flag;
            }
            else{
                if (flag == 1 || flag == 0){
                    cout << temp;
                }
                else{
                    cout << flag << temp;
                }
                flag = 1;
            }
            if (t == (char)10) //如果是换行符，就停止
                break;
            temp = t;
        }
    }
    else if (F == 'D'){
        string num = "";
        char alpha1, alpha2;
        alpha1 = getchar();
        alpha2 = getchar();
        if (alpha2 == (char)10){
            cout << alpha1;
            return 0;
        }
        while (true){
            if (isdigit(alpha1)){ //第一个拿到的是数字
                for (int i = 0; i < (int)(alpha1 - '0'); i++)
                    cout << alpha2;
                alpha1 = getchar();
                if (alpha1 == (char)10)
                    break;
                alpha2 = getchar();
            }
            else{ //第一个拿到的不是数字
                cout << alpha1;
                alpha1 = alpha2;
                if (alpha1 == (char)10)
                    break;
                alpha2 = getchar();
            }
        }
    }

    return 0;
}