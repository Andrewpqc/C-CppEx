/**
 * 1007 素数对猜想 有什么问题？有什么问题？有什么问题？部分正确。崩溃啊
 */ 
#include <iostream>
#include <vector>
using namespace std;

int main (void){
    int num, flag, count = 0;
    vector<int> IntVec;
    IntVec.push_back(2);
    cin >> num;
    for (int i = 3; i < num; i++){
        flag = 0;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
                ++ flag;
        if (flag == 0)
            IntVec.push_back(i); 
    }
    int size = IntVec.size();
    for(int i = 1;i < size;i ++){
        if(IntVec[i] - IntVec[i-1] == 2)
            ++ count;
    }

    cout<<count<<endl;
    return 0;
}