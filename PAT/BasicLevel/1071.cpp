#include <iostream>
using namespace std;

int main (void){
    int T,K;
    cin>>T>>K;
    int a[K][4];
    for(int i=0;i<K;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<K;i++){
        if(T<=0){
            cout<<"Game Over."<<endl;
            return 0;
        }
        if(a[i][2]>T){
            cout<<"Not enough tokens.  Total = "<<T<<"."<<endl;
        }else{
            if((a[i][0]<a[i][3]&&a[i][1]==1)||(a[i][0]>a[i][3]&&a[i][1]==0)){
            //赌赢了
                T+=a[i][2];
                cout<<"Win "<<a[i][2]<<"!  Total = "<<T<<"."<<endl;
            }else{
            //赌输了
                T-=a[i][2];
                cout<<"Lost "<<a[i][2]<<"!  Total = "<<T<<"."<<endl;
            }   
        }
    }
    return 0;
}