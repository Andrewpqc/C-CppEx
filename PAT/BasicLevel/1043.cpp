/**
 * 输出PATest
 **/ 

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string a;
    int flags[6] = {0}; //分别存放P,A,T,e,s,t的个数
    cin >> a;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == 'P')
            flags[0]++;
        else if (a[i] == 'A')
            flags[1]++;
        else if (a[i] == 'T')
            flags[2]++;
        else if (a[i] == 'e')
            flags[3]++;
        else if (a[i] == 's')
            flags[4]++;
        else if (a[i] == 't')
            flags[5]++;
    }

    int sum = 0;
    for (int i = 0; i < 6; i++)
        sum += flags[i];

    while (sum > 0){
        if (flags[0]){
            cout << "P";
            flags[0]--;
            sum--;
        }
        if (flags[1]){
            cout << "A";
            flags[1]--;
            sum--;
        }
        if (flags[2]){
            cout << "T";
            flags[2]--;
            sum--;
        }
        if (flags[3]){
            cout << "e";
            flags[3]--;
            sum--;
        }
        if (flags[4]){
            cout << "s";
            flags[4]--;
            sum--;
        }
        if (flags[5]){
            cout << "t";
            flags[5]--;
            sum--;
        }
    }

    return 0;
}