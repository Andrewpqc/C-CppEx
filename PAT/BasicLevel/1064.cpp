#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool in_or_not(int temp, vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        if (temp == v[i]){
            return true;
        }
    }
    return false;
}

int main(void){
    size_t count;
    cin >> count;
    vector<string> v;
    vector<int> w;
    string temp;
    for (int i = 0; i < count; i++){
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++){
        int sum = 0;
        for (int j = 0; j < v[i].size(); j++){
            sum += (int)(v[i][j] - '0');
        }
        if (!in_or_not(sum, w)){
            w.push_back(sum);
        }
    }

    sort(w.begin(), w.end());
    cout << w.size() << endl;
    for (int i = 0; i < w.size() - 1; i++){
        cout << w[i] << " ";
    }
    cout << w[w.size() - 1];
    return 0;
}