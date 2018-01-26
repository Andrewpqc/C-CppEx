/**
 * 1057
 **/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void){
    string s;
    getline(cin, s);
    int sum = 0;
    for (int i = 0; i < s.size(); i++){
        char ch = s.at(i);
        if (isalpha(ch)){
            ch = tolower(ch);
            sum += (int)ch - 96;
        }
    }
    int count_1 = 0;
    int count_0 = 0;
    while (sum){
        if (sum % 2){
            count_1++;
        }
        else{
            count_0++;
        }
        sum = sum / 2;
    }
    cout << count_0 << " " << count_1 << endl;
    return 0;
}