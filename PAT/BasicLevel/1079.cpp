#include <iostream>
#include <string>
using namespace std;

bool is_palindromic_number(string s)
{
    //如果是个位数，则只有0是回文数
    if (s.size() == 1)
    {
        if (s == "0")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
string get_reverse(string s)
{
    string s_reverse = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        s_reverse += s.at(i);
    }
    return s_reverse;
}

string add_with_self_reverse(string s, string s_reverse)
{
    string sum = "";
    string sum_reverse = "";
    int jinwei = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int a = (int)(s[i] - '0');
        int b = (int)(s_reverse[i] - '0');
        int jinwei2 = (a + b + jinwei) / 10;
        int remain = (a + b + jinwei) % 10;
        jinwei = jinwei2;
        sum += (char)(remain + 48);
        if (i == 0 && jinwei)
        {
            sum += (char)(jinwei + 48);
        }
    }
    for (int i = sum.size() - 1; i >= 0; i--)
    {
        sum_reverse += sum.at(i);
    }
    return sum_reverse;
}

int main(void)
{
    string A;
    cin >> A;
    if (is_palindromic_number(A))
    {
        cout << A << " is a palindromic number." << endl;
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        string B = get_reverse(A);
        string C = add_with_self_reverse(A, B);
        cout << A << " + " << B << " = " << C << endl;
        if (is_palindromic_number(C))
        {
            cout << C << " is a palindromic number." << endl;
            return 0;
        }
        else
        {
            A = C;
        }
    }
    cout << "Not found in 10 iterations." << endl;
    return 0;
}