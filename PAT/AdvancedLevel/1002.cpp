#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool handler(pair<int, float> t, vector<pair<int, float>> &v){
    for (int i = 0; i < v.size(); i++){
        if (t.first == v[i].first){
            v[i].second += t.second;
            return true;
        }
    }
    v.push_back(t);
    return false;
}

bool mycondtion(pair<int, float> t1, pair<int, float> t2){
    return t1.first > t2.first;
}
int main(void){
    size_t count1, count2;
    cin >> count1;
    vector<pair<int, float>> v;
    for (int i = 0; i < count1; i++){
        int temp_int;
        float temp_float;
        cin >> temp_int >> temp_float;
        pair<int, float> p(temp_int, temp_float);
        handler(p, v);
    }
    cin >> count2;
    for (int i = 0; i < count2; i++){
        int temp_int;
        float temp_float;
        cin >> temp_int >> temp_float;
        pair<int, float> p(temp_int, temp_float);
        handler(p, v);
    }
    sort(v.begin(), v.end(), mycondtion);
    cout << v.size() << " ";
    int i;
    for (i = 0; i < v.size() - 1; i++){
        cout << v[i].first << " ";
        cout << v[i].second << " ";
    }
    cout << v[i].first << " ";
    cout << v[i].second;
    return 0;
}