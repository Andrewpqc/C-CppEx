#include <iostream>
#include <vector>
#include <string>
using namespace std;

int find_rank(string target, vector<pair<int, string>> &set){
    for (vector<pair<int, string>>::iterator it = set.begin(); it != set.end(); it++){
        if (target == it->second){
            return it->first;
        }
    }
    return 0;
}

bool is_in_or_not(string target, vector<string> &v){
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++){
        if (*it == target){
            return true;
        }
    }
    return false;
}

bool is_prime_number(int a){
    for (int i = 2; i * i <= a; i++){
        if (a % i == 0){
            return false;
        }
    }
    return true;
}
int main(void){
    size_t count1;
    size_t count2;
    vector<pair<int, string>> a;
    vector<string> b;
    vector<string> c;
    cin >> count1;
    for (int i = 0; i < count1; i++){
        string temp;
        cin >> temp;
        a.push_back(make_pair(i + 1, temp));
    }

    cin >> count2;
    for (int i = 0; i < count2; i++){
        string temp;
        cin >> temp;
        c.push_back(temp);
    }

    for (int i = 0; i < c.size(); i++){
        string temp = c[i];
        int rank = find_rank(temp, a);
        if (!rank){
            cout << temp << ": Are you kidding?" << endl;
        }
        else{
            if (is_in_or_not(temp, b)){
                cout << temp << ": Checked" << endl;
            }
            else{
                b.push_back(temp);
                if (rank == 1){
                    cout << temp << ": Mystery Award" << endl;
                }
                else if (is_prime_number(rank)){
                    cout << temp << ": Minion" << endl;
                }
                else{
                    cout << temp << ": Chocolate" << endl;
                }
            }
        }
    }
    return 0;
}