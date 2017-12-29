/**
 *有理数四则运算 这题好变态啊,我见过这世界上最恶心的一道题就是它了
 **/
#include <iostream>
#include <cctype>
#include <cstdlib>
// n分子，m分母,f正负　true为正
void print(int n,int m,bool f){
    if(f){//正数
        if(n<m)
            cout<<n<<'/'<<m<<" ";
        else if(n>=m){
            int remainer=n%m;
            if(!remainer){//余数为０
                cout<<n/m<<" ";
            }else{//余数不为０
                int nx=n-m*remainer;
                cout<<n/m<<" "<<nx<<m<<" ";
            }
        }
    }else{//负数
        if(n<m)
            cout<<"(-"<<n<<'/'<<m<<")"<<" ";
        else if(n>=m){
            int remainer=n%m;
            if(!remainer){//余数为０
                cout<<"(-"<<n/m<<")"<<" ";
            }else{//余数不为０
                int nx=n-m*remainer;
                cout<<"(-"<<n/m<<" "<<nx<<m<<")"<<" ";
            }
        }

    }
}

void print+(int n1,int m1,int n2,int m2,bool f1,bool f2){
    //n1*m2 n2*m1 m1*m2 f1 f2
    if(f1&&f2){//都为正
        int sum=n1*m2+n2*m1;
        int remainer=sum%(m1*m2);
        if(!remainer)
            cout<<sum/(m1*m2)<<endl;
        else{//余数不为0
            int t=sum-sum/(m1*m2)*m1*m2;
            cout<<sum/(m1*m2)<<" "<<t<<"/"<<m1*m2<<endl;
        }
    }
    else if(!f1&&!f2){//都为负
        int sum=n1*m2+n2*m1;
        int remainer=sum%(m1*m2);
        if(!remainer)
            cout<<"(-"<<sum/(m1*m2)<<")"<<endl;
        else{//余数不为0
            int t=sum-sum/(m1*m2)*m1*m2;
            cout<<"(-"<<sum/(m1*m2)<<" "<<t<<"/"<<m1*m2<<")"<<endl;
        }
    }
    else if(f1 && !f2){//1为＋,２为-
        //可以转化为print-

    }
    else if(!f1 && f2){//１为－，２为＋
        
    }


};
void print-(int n1,int m1,int n2,int m2,bool f1,bool f2){

};
void print*(int n1,int m1,int n2,int m2,bool f1,bool f2){

};
void print/(int n1,int m1,int n2,int m2,bool f1,bool f2){

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


    




    return 0;
}

