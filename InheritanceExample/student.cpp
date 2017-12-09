#include <iostream>
#include <string>
#include "student.h"
using namespace std;
using namespace human_namespace;

namespace student_namespace{
    Student::Student(string _name,int _age,string _schoolName):Human(_name,_age),schoolName(_schoolName){
        //主体有意留空
    }

    Student::Student():Human(),schoolName("none"){
        //主体有意留空
    }

    void Student::setSchoolName(string _schoolName){
        schoolName=_schoolName;
    }

    string Student::getSchoolName(){
        return schoolName;
    }

    void Student::studying(void){
        cout<<"我是学生"<<getName()<<"，我在学习！！！"<<endl;
    }
}
