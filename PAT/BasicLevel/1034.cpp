/**
 *有理数四则运算 这题好变态啊,我见过这世界上最恶心的一道题就是它了,但是写出来成就感满满啊ls
 **/
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

struct Pair{
    int a;
    int b;
};

//输入两个数a,b给出a/b的最简单形式a'/b',返回a',b'
//这里的前提条件是a>=1,b>=2,a<b,且a,b都为正整数
struct Pair simplify_machine(int a,int b){
    struct Pair P;
    if(a==1||b==2){
        P.a=a;
        P.b=b;
    }else{
        //不断除以a,b的公约数，直到a,b互质
        int temp=a;
        for(int i=2;i<=temp;i++){
            if(a%i==0 && b%i==0){
                a=a/i;
                b=b/i;
                temp=a;
                i=1;
            }
        }
        P.a=a;
        P.b=b;
    }
    return P;
}



// n分子，m分母,f正负　true为正
void print(int n,int m,bool f){
    if(n==0){
        cout<<0<<" ";
        return ;
    }
    if(m==0){
        cout<<"Inf"<<endl;
        return ;
    }
    if(f){//正数
        if(n<m)
            cout<<n<<'/'<<m<<" ";
        else if(n>=m){
            int remainer=n%m;
            if(!remainer){//余数为０
                cout<<n/m<<" ";
            }else{//余数不为０
                struct Pair P=simplify_machine(remainer,m);
                cout<<n/m<<" "<<P.a<<'/'<<P.b<<" ";
            }
        }
    }else if(!f){//负数
        if(n<m){
            struct Pair P=simplify_machine(n,m);
            cout<<"(-"<<P.a<<'/'<<P.b<<")"<<" ";
        }
        else if(n>=m){
            int remainer=n%m;
            if(!remainer){//余数为０
                cout<<"(-"<<n/m<<")"<<" ";
            }else{//余数不为０
                struct Pair P=simplify_machine(remainer,m);
                cout<<"(-"<<n/m<<" "<<P.a<<"/"<<P.b<<")"<<" ";
            }
        }

    }
}

void add(int n1,int m1,int n2,int m2,bool f1,bool f2){
    //n1*m2 n2*m1 m1*m2 f1 f2
    if(f1&&f2){//都为正
        print(n1*m2+n2*m1,m1*m2,true);
        cout<<endl;
    }
    else if(!f1&&!f2){//都为负
        print(n1*m2+n2*m1,m1*m2,false);
        cout<<endl;
    }
    else if(f1 && !f2){//1为＋,２为-
        int sum=n1*m2-n2*m1;
        if(sum>=0){
            print(sum,m1*m2,true);
            cout<<endl;
        }else{
            print(-sum,m1*m2,false);
            cout<<endl;
        }

    }
    else if(!f1 && f2){//１为－，２为＋
        int sum=n2*m1-n1*m2;
        if(sum>=0){
            print(sum,m1*m2,true);
            cout<<endl;
        }else{
            print(sum,m1*m2,false);
            cout<<endl;
        }
    }


};
void shorten(int n1,int m1,int n2,int m2,bool f1,bool f2){
    // if(f1&&f2){//同为正
    //     add(n1,m1,n2,m2,f1,!f2);
    // }
    // else if(!f1&&!f2){//同为负
    //     add(n1,m1,n2,m2,f1,!f2);
    // }
    // else if(!f1&&f2){
    //     add(n1,m1,n2,m2,f1,!f2)
    // }
    // else if(f1&&!f2){
    //     add(n1,m1,n2,m2,f1,!f2);
    // }
    //写完上面这么多，才发现就等于下面这一句:(
    add(n1,m1,n2,m2,f1,!f2);
};
void mult(int n1,int m1,int n2,int m2,bool f1,bool f2){
    if((f1&&f2) || (!f1&&!f2)){
        print(n1*n2,m1*m2,true);
        cout<<endl;
    }
    else{
        print(n1*n2,m1*m2,false);
        cout<<endl;
    }
};
void chu(int n1,int m1,int n2,int m2,bool f1,bool f2){
    if((f1&&f2) || (!f1&&!f2)){
        print(n1*m2,m1*n2,true);
        cout<<endl;
    }
    else{
        print(n1*m2,m1*n2,false);
        cout<<endl;
    }
};


int main (void){
    bool f1,f2;//记录两个数的正负情况ture:+,false:-
    string s1,s2;//收集来自stdin的两个字符串
    string s11="",s12="",s21="",s22="";//分别记录s1,s2的分子和分母
    cin>>s1>>s2;
    f1=(isdigit(s1[0]))?true:false;
    f2=(isdigit(s2[0]))?true:false;
    
    //切割s1
    bool flag1=true;
    for(int i=((f1)?0:1);i<s1.size();i++){
        if(s1[i]=='/'){
            flag1=false;
            continue;
        }
        if(flag1)
            s11+=s1[i];
        else
            s12+=s1[i];
    }
    
    //切割s2
    bool flag2=true;
    for(int i=((f2)?0:1);i<s2.size();i++){
        if(s2[i]=='/'){
            flag2=false;
            continue;
        }
        if(flag2)
            s21+=s2[i];
        else
            s22+=s2[i];
    }

    int n11=atoi(s11.c_str());
    int n12=atoi(s12.c_str());
    int n21=atoi(s21.c_str());
    int n22=atoi(s22.c_str());
    //开始打印了
    print(n11,n12,f1);
    cout<<"+"<<" ";
    print(n21,n22,f2);
    cout<<"="<<" ";
    add(n11,n12,n21,n22,f1,f2);

    print(n11,n12,f1);
    cout<<"-"<<" ";
    print(n21,n22,f2);
    cout<<"="<<" ";
    shorten(n11,n12,n21,n22,f1,f2);
    
    print(n11,n12,f1);
    cout<<"*"<<" ";
    print(n21,n22,f2);
    cout<<"="<<" ";
    mult(n11,n12,n21,n22,f1,f2);

    print(n11,n12,f1);
    cout<<"/"<<" ";
    print(n21,n22,f2);
    cout<<"="<<" ";
    chu(n11,n12,n21,n22,f1,f2);
    return 0;
}

