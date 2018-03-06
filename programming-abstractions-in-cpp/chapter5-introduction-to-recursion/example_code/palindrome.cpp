#include <iostream>
#include <string>
using namespace std;

bool isPalindrome_recursion(string);
bool isPalindrome_recursion_tool(string, int, int);
bool isPalindrome_recursion2(string);

int main(void){
    cout << isPalindrome_recursion("noon") << endl;
    cout << isPalindrome_recursion("leael") << endl;
    cout << isPalindrome_recursion("hello") << endl;
    cout << "----------------------------" << endl;
    cout << isPalindrome_recursion2("noon") << endl;
    cout << isPalindrome_recursion2("leael") << endl;
    cout << isPalindrome_recursion2("hello") << endl;
    return 0;
}

//下面的使用substr的方法效率不高，我们可以改成直接传下标的方式
bool isPalindrome_recursion(string s){
    size_t len = s.length();
    if (len <= 1){
        return true;
    }
    else{
        return (s.at(0) == s.at(len - 1) && isPalindrome_recursion(s.substr(1, len - 2)));
    }
}

//使用下标的方式
bool isPalindrome_recursion_tool(string s, int pos_start, int pos_end){
    if (pos_end - pos_start < 1){
        return true;
    }
    else{
        return (s.at(pos_start) == s.at(pos_end) && isPalindrome_recursion_tool(s, pos_start + 1, pos_end - 1));
    }
}

bool isPalindrome_recursion2(string s){
    size_t len = s.length();
    return isPalindrome_recursion_tool(s, 0, len - 1);
}