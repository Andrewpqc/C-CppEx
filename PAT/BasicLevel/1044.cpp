/**
 * 火星数字
 **/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr",
                "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"}; //个位
string b[12] = {"tam", "hel", "maa", "huh", "tou", "kes",
                "hei", "elo", "syy", "lok", "mer", "jou"}; //十位

int find_post_in_a(string s){
    for (int i = 0; i < 13; i++)
        if (a[i] == s)
            return i;
    return 0;
}

int find_post_in_b(string s){
    for (int i = 0; i < 12; i++)
        if (b[i] == s)
            return i + 1;
    return -1;
}

int deal_with_mars_marks(string s){
    string s1 = s.substr(0, s.find(" "));
    string s2 = s.substr(s.find(" ") + 1);
    int gewei = find_post_in_a(s2);
    int shiwei = find_post_in_b(s1);
    return shiwei * 13 + gewei;
}

string deal_with_earth_marks(string s){
    int num = atoi(s.c_str());
    int c[4] = {-1};
    int flag = 0;
    do{
        c[flag++] = num % 13;
        num /= 13;
    } while (num);
    if (flag == 2){
        return b[c[0]+1] + " " + a[c[1]];
    }
    else{
        return a[c[0]];
    }
}
int main(void){
    int count;
    string s;
    cin >> count;
    vector<string> ss;
    getchar(); //读取一个换行符，防止该换行符被下面的getline读到
    for (int i = 0; i < count; i++){
        getline(cin, s);
        ss.push_back(s);
    }

    for (int i = 0; i < count; i++){
        if (isalpha(ss[i][0])){ //第一个字符为字母，表明该文字是火星文字
            int num = deal_with_mars_marks(ss[i]);
            cout << num << endl;
        }
        else{ //否则表明是地球数字
            string str = deal_with_earth_marks(ss[i]);
            cout << str << endl;
        }
    }
    return 0;
}