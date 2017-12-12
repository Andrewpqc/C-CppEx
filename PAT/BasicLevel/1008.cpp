/**
 * 数组循环右移问题,卧槽，又有什么问题啊？做检测程序的人有问题吧！！！！！
 */ 

#include <iostream>
using namespace std;

int main (void){
    //数组中有N个整数，循环移动M个位置
    int M,N;
    cin >> N >> M;
    int array[N];
    for(int i=0;i<N;i++)
        cin>>array[i];

    for(int i=0;i<M;i++){
        int temp=array[N-1];//先找个变量保存最后一个数，以免移动时被覆盖
        for(int j=N-1;j>0;j--)
            array[j]=array[j-1];
        array[0]=temp;
    }

    //输出
    for(int i=0;i<N;i++)
        cout<<array[i]<<" ";
    
    cout<<"\b";

    return 0;
}