#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "human.h"
using namespace human_namespace;
using namespace std;
namespace student_namespace{

    class Student:public Human{
    public:
        Student(string _name,int _age,string _schoolNmae);
        Student();
        void setSchoolName(string _schoolName);
        string getSchoolName(void);
        void studying(void);
    private:
        string schoolName;
    };
}

#endif