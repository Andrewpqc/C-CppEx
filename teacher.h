#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "human.h"
using namespace std;
using namespace human_namespace;

namespace teacher_namespace{
    
        class Teacher: public Human{
        public:
            Teacher(string _name,int _age,string _subject);
            Teacher();
            void setSubject(string _schoolName);
            string getSubject(void);
            void teaching(void);
        private:
            string subject;
        };
    }
#endif