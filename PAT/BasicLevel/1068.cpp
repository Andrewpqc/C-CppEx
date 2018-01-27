#include <iostream>
#include <cmath>
using namespace std;

int main (void){
    int M,N,edge;
    int x,y;
    int count=0;
    long target;
    cin>>M>>N>>edge;
    long map[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            bool b1=((map[i][j]-map[i][j+1])>edge);
            bool b2=((map[i][j]-map[i][j-1])>edge);
            bool b3=((map[i][j]-map[i+1][j])>edge);
            bool b4=((map[i][j]-map[i-1][j])>edge);
            bool b5=((map[i][j]-map[i+1][j+1])>edge);
            bool b6=((map[i][j]-map[i+1][j-1])>edge);
            bool b7=((map[i][j]-map[i-1][j+1])>edge);
            bool b8=((map[i][j]-map[i-1][j-1])>edge);
            if(b1&&b2&&b3&&b4&&b5&&b6&&b7&&b8){
                x=i+1;
                y=j+1;
                target=map[i][j];
                count++;
            }
        }
    }

    if(!count){
        cout<<"Not Exist"<<endl;
    }else if(count==1){
        cout<<"("<<y<<","<<" "<<x<<"): "<<target<<endl;
    }else{
        cout<<"Not Unique"<<endl;
    }

    return 0;
}