#include <iostream>
#include <string>
using namespace std;
void ListPermutations(string str);
void RecursivePermute(string perfix, string rest);

int main(void){
    ListPermutations("ABC");
    return 0;
}

void ListPermutations(string str){
    RecursivePermute("", str);
}

void RecursivePermute(string perfix, string rest){
    if (rest == ""){
        cout << perfix << endl;
    }
    else{
        for (int i = 0; i < rest.length(); i++){
            string newPerfix = perfix + rest[i];
            string newRest = rest.substr(0, i) + rest.substr(i + 1);
            RecursivePermute(newPerfix, newRest);
        }
    }
}