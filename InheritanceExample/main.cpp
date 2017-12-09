#include <iostream>
#include "student.h"
#include "teacher.h"
using namespace std;
using namespace student_namespace;
using namespace teacher_namespace;
int main() {
    Student s1=Student("小明",25,"黄冈中学");
    Student s2;

    Teacher t1=Teacher("老王",40,"语文");
    Teacher t2;

    cout<<s1.getName()<<endl;
    cout<<s2.getName()<<endl;
    s1.studying();
    s1.setName("小小明");
    s1.studying();

    cout<<t1.getSubject()<<endl;
    cout<<t2.getAge()<<endl;

}