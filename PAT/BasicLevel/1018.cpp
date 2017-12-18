/**
 * 1018　石头剪子布 这道题让人深刻感受到python的强大，c++可用的数据结构太少了，
 * 另外最近几道题感觉都是体力题啊
 */ 
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(void){
    int record_count;
    int jia_win=0,jia_lose=0,yi_win=0,yi_lose=0,draw=0;
    map<char,int> jia_win_map;
    map<char,int> yi_win_map;
    jia_win_map['C']=0;
    jia_win_map['J']=0;
    jia_win_map['B']=0;
    yi_win_map['C']=0;
    yi_win_map['J']=0;
    yi_win_map['B']=0;
    int jia_B=0,jia_J=0,jia_C=0;
    int yi_B=0,yi_J=0,yi_C=0;
    vector<char> records;
    char jia,yi;
    cin >> record_count;
    for(int i=0;i<record_count;i++){
        cin >> jia >> yi;
        records.push_back(jia);
        records.push_back(yi);
    }
    
    //统计数据
    for(int i=1;i<records.size();i+=2){
        if(records[i-1]==records[i]){//平局
            ++draw;
        }
        else{
            if(records[i-1]=='C'&&records[i]=='J'){
                ++jia_win;
                ++yi_lose;
                ++jia_win_map['C'];
            }else if(records[i-1]=='J'&&records[i]=='B'){
                ++jia_win;
                ++yi_lose;
                ++jia_win_map['J'];
            }else if(records[i-1]=='B'&&records[i]=='C'){
                ++jia_win;
                ++yi_lose;
                ++jia_win_map['B'];
            }else if(records[i]=='C'&&records[i-1]=='J'){
                ++yi_win;
                ++jia_lose;
                ++yi_win_map['C'];
            }else if(records[i]=='J'&&records[i-1]=='B'){
                ++yi_win;
                ++jia_lose;
                ++yi_win_map['J'];
            }else if(records[i]=='B'&&records[i-1]=='C'){
                ++yi_win;
                ++jia_lose;
                ++yi_win_map['B'];
            }
        }
    }

    cout<<" "<<jia_win<<" "<<draw<<" "<<jia_lose<<endl;
    cout<<" "<<yi_win<<" "<<draw<<" "<<yi_lose<<endl;
    return 0;
}