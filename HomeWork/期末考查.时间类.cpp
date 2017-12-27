#include <iostream>
using namespace std;

class Time{
  private:
    int hours;   //表示小时
    int minutes; //表示分钟
  public:
    Time(int h=0, int m=0);                                //构造函数
    Time(const Time &t);                                   //复制构造函数
    ~Time();                                               //析构函数
    friend Time operator+(const Time &t, int m);           //加分钟
    friend Time operator+(int h, const Time &t);           //加小时
    friend Time operator+(const Time &t1, const Time &t2); //两个时间对象相加
    friend Time operator*(const Time &t, int d);           //时间与整数相乘
    friend Time operator*(int d, const Time &t);           //整数与时间相乘
    friend ostream &operator<<(ostream &os, Time &rs);     //重载<<
    friend istream &operator>>(istream &is, Time &rs);     //重载>>
};

//构造函数，支持有参数和无参数两种情况
Time::Time(int h = 0, int m = 0){
    hours = h;
    minutes = m;
}

//复制构造函数
Time::Time(const Time &t){
    hours = t.hours;
    minutes = t.minutes;
}

//析构函数
Time::~Time()
{
    // cout<<hours<<":"<<minutes<<"被注销"<<endl;
    ;
}

//重载operator+,加分钟
Time operator+(const Time &t, int m){
    Time temp;
    temp.minutes = m + t.minutes;
    temp.hours = t.hours + temp.minutes / 60;
    temp.minutes %= 60;
    return temp;
}

//重载operator+,加小时
Time operator+(int h, const Time &t){
    Time temp;
    temp.minutes = t.minutes;
    temp.hours = t.hours + h;
    return temp;
}

//重载operator+,两个Time对象相加
Time operator+(const Time &t1, const Time &t2){
    Time temp;
    temp.minutes = t1.minutes + t2.minutes;
    temp.hours = t1.hours + t2.hours + temp.minutes / 60;
    temp.minutes %= 60;
    return temp;
}

//重载operator*,整数与时间对象相乘
Time operator*(int d, const Time &t){
    Time temp;
    temp.minutes = (t.minutes) * d;
    temp.hours = (t.hours) * d + temp.minutes / 60;
    temp.minutes %= 60;
    return temp;
}

//重载operator*,时间对象与整数相乘
Time operator*(const Time &t, int d){
    Time temp;
    temp.minutes = (t.minutes) * d;
    temp.hours = (t.hours) * d + temp.minutes / 60;
    temp.minutes %= 60;
    return temp;
}

//重载<<
ostream &operator<<(ostream &os, Time &rs){
    os << rs.hours << "小时" << rs.minutes << "分钟";
    return os;
}

//重载>>
istream &operator>>(istream &is, Time &rs){
    is >> rs.hours >> rs.minutes;
    return is;
}

int main(void){
    Time t1; //无参方式定义时间对象t1，初值默认为0小时0分钟
    cout << "t1=" << t1 << endl;

    Time t2(2, 40); //有参方式定义时间对象t2，初值设为2小时40分钟
    cout << "t2=" << t2 << endl;

    t1 = 2 + t2; //t2表示的时间上加上2小时
    cout << "t1=2+t2=" << t1 << endl;

    t1 = t2 + 30; //t2表示的时间上加上30分钟
    cout << "t1=t2+30=" << t1 << endl;

    t1 = t2 * 2; //t2表示的时间扩大2倍后赋值给t1
    cout << "t1=t2*2=" << t1 << endl;

    t1 = 3 * t2; //t2表示的时间扩大3倍后赋值给t1
    cout << "t1=3*t2=" << t1 << endl;

    Time t3;
    cout << "输入t1和t3的数据成员的值（以空格作为分隔符）" << endl;
    cin >> t1 >> t3;
    cout << endl;
    cout << "t1=" << t1 << endl;
    cout << "t3=" << t3 << endl;

    t1 = t2 + t3; //t2表示的时间与t3表示的时间之和赋值给t1
    cout << "t1=t2+t3=" << t1 << endl;
    return 0;
}