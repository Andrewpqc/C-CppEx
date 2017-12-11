/**
 * 1004 成绩排名　
 * PAT坑爹啊，为什么部分正确，还有什么错误啊？？？？？
 */ 

#include <iostream>
using namespace std;

typedef struct Node{
    char name[10];
    char id[10];
    int score;
}Student;

void output(Student s){
    cout<<s.name<<" "<<s.id;
}
void exch(Student& s1,Student& s2){
    Student temp=s1;
    s1=s2;
    s2=temp;
}

int main(void){
    int stu_num;
    cin>>stu_num;
    Student students[stu_num];
    for(int i=0;i<stu_num;i++){
        Student s;
        cin>>s.name>>s.id>>s.score;
        students[i]=s;
    }

    Student max_min[2]={students[0],students[0]};

    for(int i=1;i<stu_num;i++){
        if(students[i].score>max_min[0].score)
            exch(students[i],max_min[0]);
        if(students[i].score<max_min[1].score)
            exch(students[i],max_min[1]);
    }

    output(max_min[0]);
    cout<<endl;
    output(max_min[1]);
    return 0;
}