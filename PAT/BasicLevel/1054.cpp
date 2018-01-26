/**
 * 求平均值
 **/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

bool legal_or_not(string s){
    if (!isdigit(s.at(0)) && (s.at(0) != '+') && (s.at(0) != '-')){ //第一个字符不是数字,不是+,不是-
        return false;
    }
    for (int i = 1; i < s.size(); i++){
        if (!isdigit(s.at(i)) && s.at(i) != '.'){ //中间出现了非数字字符，但不是小数点'.'
            return false;
        }
        if (s.at(i) == '.'){ //出现了小数点，下面考查小数点后面的位数是否符合要求
            if (i + 2 < s.size() - 1){ //小数点后面多于两位
                return false;
            }
        }
    }
    double d = atof(s.c_str());
    if (d > 1000 || d < -1000){
        return false;
    }
    return true;
}

int main(void){
    size_t ok_count = 0;
    size_t count;
    double sum = 0.0;
    cin >> count;
    string temp;
    for (int i = 0; i < count; i++){
        cin >> temp;
        if (legal_or_not(temp)){
            ++ok_count;
            sum += atof(temp.c_str());
        }
        else{
            cout << "ERROR: " << temp << " is not a legal number" << endl;
        }
    }

    if (ok_count == 0){
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else{
        cout << "The average of " << ok_count << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << sum / ok_count << endl;
    }
    return 0;
}