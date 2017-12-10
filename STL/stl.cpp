#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Node{
string name;
string id;
float scores[3];
float average;
}Student;

//添加数据
void addStudent(vector<Student>& myvec){
auto count=0;
auto score1=0.0,score2=0.0,score3=0.0;
cout<<"请输入你要添加的学生信息的条数:"<<endl;
cout<<">>>";
cin>>count;
for (auto i=0;i<count;i++){
Student* ptemp=new Student;
cout<<"请输入第"<<i+1<<"个学生的信息："<<endl;
cout<<"姓名：";
cin>>ptemp->name;
cout<<"学号：";
cin>>ptemp->id;
cout<<"三门课的成绩："<<endl;
cout<<"第一门：";
cin>>score1;
cout<<"第二门";
cin>>score2;
cout<<"第三门：";
cin>>score3;
ptemp->scores[0]=score1;
ptemp->scores[1]=score2;
ptemp->scores[2]=score3;
auto score=(score1+score2+score3)/3;
ptemp->average=score;
//连接节点
myvec.push_back(*ptemp);
free(ptemp);
}
}

//输出头信息
void printTitle(void){
cout<<"姓名　"<<"学号　"<<"第一门成绩　"<<"第二门成绩　"<<"第三门成绩　"<<"平均成绩"<<endl;
}

//排序条件
bool sortCondition(Student& s1,Student& s2){
return s1.average>s2.average;
}

//打印某一成员的所有信息
void print(Student& s){
cout<<s.name<<" "<<s.id<<" "<<s.scores[0]<<" "<<s.scores[1]<<" "<<s.scores[2]<<" "<<s.average<<endl;
}

//排序并输出平均分最高者的信息
void sortAndprint(vector<Student>& myvec){
//排序
sort(myvec.begin(),myvec.end(),sortCondition);
cout<<"平均成绩最高的人的信息："<<endl;
printTitle()
print(myvec.at(0))
}

int main(void){
vector<Student> myvec;
addStudent(myvec);
printTitle();
for_each(myvec.begin(),myvec.end(),print);
sortAndprint(myvec);
return 0;
}