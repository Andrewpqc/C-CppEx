//汉诺塔
#include <iostream>
using namespace std;
void moveTower(int n,char, char, char);

int main (void){
    moveTower(3,'A','B','C');
    return 0;
}

void moveTower(int n,char start, char finish, char temp){
    if(n==1){
        cout<<start<<"-->"<<finish<<endl;
    }else{
        moveTower(n-1,start,temp,finish);
        cout<<start<<"-->"<<finish<<endl;
        moveTower(n-1,temp,finish,start);
    }
}

//当一个的时候，直接将这一个从起始位置移动到目标位置
//当有n(n>1)个的时候，首先考虑将,最上面的n-1个移动到暂存区，
//然后将最下面的一个移动到目标区，后面的情形是将暂存区的n-1个
//移动到目标区，这与初始时的情形是一样的只不过问题的规模缩小了。