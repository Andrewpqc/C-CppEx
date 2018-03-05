/**
 * File:powertab.cpp
 */ 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
const int LOWER_LIMIT=0;
const int HIGH_LIMIT=12;

int main (void){
    cout<<"   |  2 |  n  |" <<endl;
    cout<<"  n| n  | 2   |" <<endl;
    cout<<"---+----+-----+-"<<endl;
    for(int i=LOWER_LIMIT;i<HIGH_LIMIT;i++){
        cout<<setw(3)<<i<<"|";
        cout<<setw(4)<<pow(i,2)<<"|";
        cout<<setw(5)<<pow(2,i)<<"|"<<endl;
    }
    return 0;
}