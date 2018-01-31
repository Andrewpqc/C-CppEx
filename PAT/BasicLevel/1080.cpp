#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
bool is_in_or_not(string student_name, vector<pair<string,int> >& all_data){
    for(int i=0;i<all_data.size();i++){
        if(all_data[i].first==student_name){
            return true;
        }
    }
    return false;
}

int main (void){
    map<string,int*>mymap;
    vector<pair<string,int> > all_data;
    vector<pair<string,int> > unique_data;
    string student_name;
    int score;
    int P,M,N;
    cin>>P>>M>>N;
    for(int i=0;i<P+M+N;i++){
        cin>>student_name>>score;
        if(!is_in_or_not(student_name,unique_data)){
            unique_data.push_back(pair<string,int>(student_name,score));//统计并收集参加考试的学生
        }
        all_data.push_back(pair<string,int>(student_name,score)); //从命令行收集数据
    }
    int table[unique_data.size()][4]={0};
    for(int j=0;j<unique_data.size();j++){
        int* p=&table[j][0];
        mymap.insert(pair<string,p>);
    }
    for(int i=0;i<P;i++){
        mymap[all_data[i].first][0]=all_data[i].second;
    }
    for(int i=P;i<M+P;i++){
        mymap[all_data[i].first][1]=all_data[i].second;
    }
    for(int i=P+M;i<N+P+M;i++){
        mymap[all_data[i].first][2]=all_data[i].second;
    }
    return 0;
}