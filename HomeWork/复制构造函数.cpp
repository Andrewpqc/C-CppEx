
//自定义字符串类型Str
#include <iostream>
#include <cstring>

using namespace std;

class Str    //定义字符串类型
{
private:
	char *str_p;  //指向字符串信息的指针变量
    int str_len;  //字符串的长度
public:
	Str(char *p="ccnu");  //构造函数，用指针p指向的字符串给宿主对象初始化
    Str(const Str&);
	void Str_output();  //输出宿主对象保存的字符串
	void Str_cpy(Str &s);  //将对象s中保存的字符串复制给宿主对象		
	void Str_cat(Str &s);  //将对象s中保存的字符串连接到宿主对象中字符串的后面
	~Str();  //析构函数，注销宿主对象分配的动态内存空间
};

Str::Str(char *p)  //用指针p指向的字符串给对象初始化
{
	str_len=strlen(p);
	str_p=new char[str_len+1];
	strcpy(str_p,p);
}//Str s1;	 Str s2("hello!");  Str s3(c);  

//赋值构造函数
Str::Str(const Str&s){
    delete [] str_p;
    str_len=s.str_len;
    str_p=new char[str_len+1];
    strcpy(str_p,s.str_p);
}


void Str::Str_output()  //输出宿主对象保存的信息
{
	cout<<"str_p="<<str_p<<endl;
	cout<<"str_len="<<str_len<<endl;
	cout<<endl;
}//s1.Str_output();

void Str::Str_cpy(Str &s)  //将对象s中保存的字符串复制给宿主对象
{
	delete []str_p;
	str_len=s.str_len;
	str_p=new char[str_len+1];
	strcpy(str_p,s.str_p);
}//s1.Str_cpy(s2);
	
void Str::Str_cat(Str &s)  //将对象s中保存的字符串连接到宿主对象中字符串的后面
{
	char *q=str_p;

	str_len=str_len+s.str_len;
	str_p=new char[str_len+1];
	str_p[0]='\0';

	strcat(str_p,q);
	strcat(str_p,s.str_p);

	delete []q;
}//s1.Str_cat(s3);

Str::~Str()  //析构函数，注销宿主对象分配的动态内存空间
{	
	cout<<"字符串"<<str_p<<"被注销！"<<endl;
	delete [] str_p;
}

	
int main(void)
{
	Str s1("hello!");  //将字符串常量"hello!"保存到对象s1中
	cout<<"输出s1中保存的字符串信息："<<endl;
	s1.Str_output();

	Str s2=s1;
	cout<<"输出s2中保存的字符串信息："<<endl;
	s2.Str_output();
	return 0;
}