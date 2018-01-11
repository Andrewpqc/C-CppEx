#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(void){
    list<char> p, c;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
        p.push_back(s1.at(i));
    for (int i = 0; i < s2.size(); i++)
        c.push_back(s2.at(i));

    list<char>::iterator it;
    list<char>::iterator it2;
    int flag = 0;
    for (it = c.begin(); it != c.end(); it++){
        for (it2 = p.begin(); it2 != p.end(); it2++){
            if (*it == *it2){
                p.erase(it2); //清除当前元素
                flag++;
                break;
            }
        }
    }

    if (flag == c.size())
        cout << "YES"<< " " << p.size() << endl;
    else
        cout << "NO"<< " " << c.size() - flag << endl;
    return 0;
}