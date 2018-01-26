/**
 * 最简分数
 **/ 
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct fenshu{
    int fenzi;
    int fenmu;
};

struct fenshu get_fenzi_and_fenmu(string s){
    struct fenshu fenshu_temp;
    size_t pos=s.find('/');
    int fenzi=atoi(s.substr(0,pos).c_str());
    int fenmu=atoi(s.substr(pos+1).c_str());
    fenshu_temp.fenmu=fenmu;
    fenshu_temp.fenzi=fenzi;
    return fenshu_temp;
}


bool check_huzhi(int i,int k){
    for(int j=2;i%j==0 && j<=i;j++){
        if(k%j==0){
            return false;
        }
    }
    return true;
}
int main (void){
    string s1,s2;
    int k;
    struct fenshu fenshu1,fenshu2;
    cin>>s1>>s2>>k;
    fenshu1=get_fenzi_and_fenmu(s1);
    fenshu2=get_fenzi_and_fenmu(s2);
    int lower_edge=(int)((fenshu1.fenzi*k)/(double)fenshu1.fenmu);
    int high_edge=(int)((fenshu2.fenzi*k)/(double)fenshu2.fenmu)+1;
    for(int i=lower_edge;i<=high_edge;i++){
        if(check_huzhi(i,k)){
            cout<<i<<'/'<<k<<" ";
        }
    }



    return 0;
}