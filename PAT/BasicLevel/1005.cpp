/**
 * 1005 继续3n+1猜想
 */ 
#include <iostream>
using namespace std;

//最坏的情况就是n(1<n<=100)全被覆盖了
int coverd[100]={-1};

//向coverd列表中增加被某个数覆盖的数,判断该数是否被覆盖
void add(int a){
    //对本题目来讲，大于100的数没必要看
    if(a>100)
        return;

    int i;
    for( i = 0;coverd[i] != -1;i++){
        //这个数已经被添加过
        if(coverd[i]==a){
            return;
        }
    }
    //添加该数
    coverd[i]=a;
}

bool exsit(int a){
    int i;
    for( i = 0;coverd[i] != -1;i++){
        //这个数存在于被覆盖数的列表中
        if(coverd[i]==a){
            return true;
        }
    }
    return false;
}

int main( void ){
    int num_count;
    cin>>num_count;
    int num_array[num_count];
    int keys[num_count];
    //记录当前加到第几个key
    int position=0;

    /**
     * 题设让先输入数据个数，再另起一行，每隔一个空格输入一个整数，
     * 读入这一行的所有数据,并且存入数组，使用下面这样一个循环就可以
     */ 
    for(int i=0;i<num_count;i++){
        cin>>num_array[i];
    }

    for(int i=0;i<num_count;i++){
        //看num_array是否可以被覆盖
        int a=num_array[i];
        while (a != 1){
                if (a % 2 == 0){
                    a /= 2;
                    add(a);
                }
                else{
                    a = (3 * a + 1) / 2;
                    add(a);
                }
            }
    }
    
    for(int i=0;i<num_count;i++){
        if(!exsit(num_array[i])){
            //添加到keys中
            keys[position++]=num_array[i];
        }
    }
    //对keys排序
    for(int j=0;j<position;j++){
        for(int k=j+1;k<position;k++){
            if(keys[j]>keys[k]){
                int temp=keys[j];
                keys[j]=keys[k];
                keys[k]=temp;
            }
        }
    }

    //输出keys
    for(int i=0;i<position;i++){
        cout<<keys[i]<<" ";
    }

    //除去最后一个数字后面的空格
    cout<<"\b";
    return 0;
}