#include <iostream>
#include <cstring>
using namespace std;

class Str{
    private:
        char *str_p;
        int str_len;
    public:
        Str(const char* a="ccnu");
        Str(Str& s);
        ~Str();
        Str& operator=(Str& );
        Str& operator=(const char* a);
        friend Str operator+(const Str& s1,const Str& s2);
        friend ostream& operator<<(ostream &os, Str &rs);     //重载<<
        friend istream& operator>>(istream &is, Str &rs);     //重载>>
};

//构造函数，可以接受有参数和无参数
Str::Str(const char * a){
    size_t len=strlen(a);
    str_p= new char[len+1];
    strcpy(str_p,a); 
    str_len=len;
}

Str::Str(Str& s){
    delete [] str_p;
    str_p= new char[s.str_len+1];
    strcpy(str_p,s.str_p);
    str_len=s.str_len;
}

Str::~Str(){
    delete [] str_p;
}

Str& Str::operator=(Str &rs) {
    if(this!=&rs){
		delete[] str_p;  
	    str_len=rs.str_len;  
	    str_p=new char[str_len+1];  
	    strcpy(str_p,rs.str_p);  
	}
	return *this;
}


Str& Str::operator=(const char* a){
    delete [] str_p;
    size_t len=strlen(a);
    str_p= new char[len+1];
    strcpy(str_p,a); 
    str_len=len;
    return *this;
}

Str operator+(const Str& s1,const Str& s2){
    Str s;
    int len=s1.str_len+s2.str_len;
    s.str_p=new char[len+1];
    
    int i;
    for(i=0;i<s1.str_len;i++)
        s.str_p[i]=s1.str_p[i];
    for(int j=0;j<s2.str_len;j++)
        s.str_p[j+i]=s2.str_p[j];
    
    s.str_len=len;
    return s;
 }

ostream &operator<<(ostream &os, Str &rs){
    os<<rs.str_p<<endl;
    return os;
}


istream &operator>>(istream &is, Str &rs){
    is>>rs.str_p;
    return is;
}
int main(void)
{
	Str s1;  //无参方式定义s1，默认保存的字符串为"ccnu"  
	cout<<"s1="<<s1<<endl;

	Str s2("hello!");  //有参方式定义s2，保存的字符串为实参字符串"hello!"   
	cout<<"s2="<<s2<<endl;

	Str s3=s1;  //s3的复制构造函数被调用，实现s1对s3的深复制
	cout<<"s3="<<s3<<endl;

   Str s4;
	s4=s2;  //要求实现s2对s4的深复制
	cout<<"s4=s2="<<s4<<endl;

	s3="C++";  //将字符串常量"C++"复制到s3中
	cout<<"s3="<<s3<<endl;

    s3=s1+s2;  //s1中保存的字符串与s2中保存的字符串连接后再保存到s3中
	cout<<"s3=s1+s2="<<s3<<endl;

	s2=s2+s3;  //s2中保存的字符串与s3中保存的字符串连接后保存到s2中
	cout<<"s2=s2+s3="<<s2<<endl;
	//后面的代码作为可选功能实现
	cout<<"输入新的字符串保存到s4中"<<endl;
	cin>>s4;  
	cout<<"s4="<<s4<<endl;

    return 0;
}