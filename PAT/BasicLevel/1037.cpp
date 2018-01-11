#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;

//字符串分割
void split(const std::string &s,
           std::vector<std::string> &sv,
           const char *delim = " ")
{
    sv.clear();                            // 1.
    char *buffer = new char[s.size() + 1]; // 2.
    std::copy(s.begin(), s.end(), buffer); // 3.
    char *p = std::strtok(buffer, delim);  // 4.
    do{
        sv.push_back(p);                      // 5.
    } while ((p = std::strtok(NULL, delim))); // 6.
    return;
}

int main(void){
    ull galleon_p = 0, sickle_p = 0, knut_p = 0;
    ull galleon_a = 0, sickle_a = 0, knut_a = 0;
    ull p, a, x;
    string P, A;
    cin >> P >> A;
    vector<string> sv1, sv2;
    split(P, sv1, ".");
    split(A, sv2, ".");
    galleon_p = atol(sv1.at(0).c_str());
    sickle_p = atol(sv1.at(1).c_str());
    knut_p = atol(sv1.at(2).c_str());
    p = galleon_p * 17 * 29 + sickle_p * 19 + knut_p;
    galleon_a = atol(sv2.at(0).c_str());
    sickle_a = atol(sv2.at(1).c_str());
    knut_a = atol(sv2.at(2).c_str());
    a = galleon_a * 17 * 29 + sickle_a * 19 + knut_a;
    x = a - p; //应该找的钱
    x = x < 0 ? -x : x;
    ull g = x / (17 * 29);
    ull s = (x - g * 17 * 29) / 29;
    ull k = x - g * 17 * 29 - s * 29;
    cout << g << "." << s << "." << k << endl;
    return 0;
}