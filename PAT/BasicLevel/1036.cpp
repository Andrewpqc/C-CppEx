/**
 * 和奥巴马一起编程
 **/ 
#include <iostream>
using namespace std;

int main(void){
    int count;
    char ch;
    cin >> count >> ch;
    for (int i = 0; i < (count+1) / 2; i++){ //控制行
        for (int j = 0; j < count; j++){
            if (i == 0 || i == (count+1) / 2 - 1){
                if (j == count - 1)
                    cout << ch << endl;
                else
                    cout << ch;
            }
            else{
                if (j == count - 1)
                    cout << ch << endl;
                else if (j == 0)
                    cout << ch;
                else
                    cout << " ";
            }
        }
    }
    return 0;
}