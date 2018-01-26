/**
 * 照相排队　get 
 **/

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ostream& operator<<(ostream& os,const pair<string,int> p){
//     return os<<p.first<<" "<<p.second;
// }

bool my_sort_condition(pair<string, int> p1, pair<string, int> p2){
    if (p1.second != p2.second){
        return p1.second > p2.second; //按照身高从大到小排序
    }
    else{
        return p1.first < p2.first; //身高相同时，按照姓名的字典顺序排序排序
    }
}

void print(deque<pair<string, int>> mydeque){
    deque<pair<string, int>>::iterator it;
    for (it = mydeque.begin(); it != mydeque.end() - 1; ++it)
        cout << it->first << " ";
    it = mydeque.end() - 1;
    cout << it->first << endl;
}
int main(void){
    vector<pair<string, int>> v;
    string name;
    int height;
    size_t count, k; //count人数，k排数
    cin >> count >> k;
    for (int i = 0; i < count; i++){
        cin >> name >> height;
        v.push_back(make_pair(name, height));
    }

    //将v按照height从大到小排序，如果height相同，则按照name的字典顺序排序
    sort(v.begin(), v.end(), my_sort_condition);
    size_t t_every = count / k;                //除最后一排之外的每排的人数
    size_t t_last = count - t_every * (k - 1); //最后一排的人数
    deque<pair<string, int>> mydeque;
    bool flag = true;
    mydeque.push_back(v[0]);
    for (int i = 1; i < v.size() + 1; i++){
        if (i <= t_last){
            if (mydeque.size() == t_last){
                print(mydeque);
                mydeque.clear();
                mydeque.push_back(v[i]);
                flag = true;
                continue;
            }
            if (flag){
                mydeque.push_front(v[i]);
                flag = false;
                continue;
            }
            else{
                mydeque.push_back(v[i]);
                flag = true;
                continue;
            }
        }
        else{
            if (mydeque.size() == t_every){
                print(mydeque);
                mydeque.clear();
                mydeque.push_back(v[i]);
                flag = true;
                continue;
            }
            if (flag){
                mydeque.push_front(v[i]);
                flag = false;
                continue;
            }
            else{
                mydeque.push_back(v[i]);
                flag = true;
            }
        }
    }
    return 0;
}