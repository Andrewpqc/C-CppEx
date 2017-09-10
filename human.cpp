#include <iostream>
#include "human.h"
using namespace std;
namespace human_namespace{
    Human::Human(string _name,int _age):name(_name),age(_age){
        //有意留空
    }
    
    Human::Human():name("none"),age(18){
        //有意留空
    }
    
    string Human::getName(){
        return name;
    }
    
    void Human::setName(string _name){
        name=_name;
    }
    
    int Human::getAge(){
        return age;
    }
    
    void Human::setAge(int _age){
        age=_age;
    }
    
    bool isSameName(Human s1,Human s2){
        return s1.name==s2.name;
    }

}
