#include <iostream>
#include <cmath>
using namespace std;

class Point {
private: 
	double a;  //极坐标角的弧度
    double r;  //极坐标半径

public:  //公共成员定义类的外部接口
	
	void Set(double x,double y);  //设置数据成员，x与y表示直角坐标
    double x_offset();  //取x轴坐标分量
    double y_offset();  //取y轴坐标分量
    double angle();  //取点的极坐标角的度数
    double radius();  //取点的极坐标半径
}; 

void Point::Set(double x,double y){
    this->a=atan(y/x);
    this->r=sqrt(x*x+y*y);
}

double Point::x_offset(){
    return this->r*cos(this->a);
}

double Point::y_offset(){
    return this->r*sin(this->a);
}

double Point::angle(){
    return this->a;
}

double Point::radius(){
    return this->r;
}


int main (void){
    Point p1;
    double x,y;
    cin>>x>>y;
    p1.Set(x,y);
    cout<<p1.x_offset()<<endl;
    cout<<p1.y_offset()<<endl;
    cout<<p1.radius()<<endl;
    cout<<p1.angle()<<endl;
    return 0;
}