#include <iostream>
#include <string>
#include "teacher.h"
using namespace std;
using namespace human_namespace;

namespace teacher_namespace{
    Teacher::Teacher(string _name,int _age,string _subject):Human(_name,_age),subject(_subject){
        //主体有意留空
    }

    Teacher::Teacher():Human(),subject("none"){
        //主体有意留空
    }

    void Teacher::setSubject(string _subject){
        subject=_subject;
    }

    string Teacher::getSubject(){
        return subject;
    }

    void Teacher::teaching(void){
        cout<<"我是一个老师，我在教书！！！"<<endl;
    }
}
