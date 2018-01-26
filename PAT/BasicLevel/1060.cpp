/**
 * 艾丁顿数
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    size_t count;
    int temp;
    cin >> count;
    vector<int> v;
    for (int i = 0; i < count; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1, flag = 0; i >= 0; i--, flag++){
        if (v[i] == flag){
            cout << v[i] << endl;
            break;
        }
    }
    return 0;
}