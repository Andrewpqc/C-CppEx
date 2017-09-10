#ifndef HUMAN_H
#define HUMAN_H

# include<iostream>
# include <string>
using namespace std;

namespace human_namespace{

class Human;
class Human{
    public:
        Human(string _name,int _age);
        Human();
        string getName();
        void setName(string _name);
        int getAge();
        void setAge(int _age);
        //下面这个函数就是Studnet类的一个友元函数
        friend bool isSameName(Human s1,Human s2);
    private:
        string name;
        int age;
};
}
#endif