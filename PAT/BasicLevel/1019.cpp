/***************************
 *       1019　数字黑洞      *
 ***************************/ 
//部分正确
#include <iostream>
#include <cmath>
using namespace std;
//插入排序的方式将四位数字按照从小到大排序
void min_to_max_sort(int * a){
    for(int i=1;i<4;i++){
        if(a[i]<a[i-1]){
            int j=i-1;
            int temp=a[i];//待插入的数据
            do{
                a[j+1]=a[j];
                --j;
            }while(j>=0 && a[j]>temp);
            a[j+1]=temp;
        }
    }
}

//插入排序的方式将四位数字按照从大到小排序
void max_to_min_sort(int * a){
    for(int i=1;i<4;i++){
        if(a[i]>a[i-1]){
            int j=i-1;
            int temp=a[i];//待插入的数据
            do{
                a[j+1]=a[j];
                --j;
            }while(j>=0 && a[j]<temp);
            a[j+1]=temp;
        }
    }
}

int array_to_integer(int *a){
    int sum=0;
    for(int i=0;i<4;i++)
        sum+=(a[3-i])*pow(10,i);
    return sum;
}

void integer_to_array_and_show(int result){
    int a[4]={0,0,0,0};
    int flag=3;
    while(result){
        a[flag--]=result%10;
        result=result/10;
    }
    for(int i=0;i<4;i++)
        cout<<a[i];
}

int main (void){
    int a[4]={0,0,0,0};
    char b[5]="0000";
    cin>>b;
    int result=0;
    for(int i=0;i<4;i++)
        a[i]=b[i]-'0';
    do{
        max_to_min_sort(a);
        int max=array_to_integer(a);
        min_to_max_sort(a);
        int min=array_to_integer(a);
        result=max-min;
        if(result==0){
            integer_to_array_and_show(max);
            cout<<" - ";
            integer_to_array_and_show(min);
            cout<<" = "<<"0000"<<endl;
            break;
        }

        integer_to_array_and_show(max);
        cout<<" - ";
        integer_to_array_and_show(min);
        cout<<" = ";
        integer_to_array_and_show(result);
        cout<<endl;
        for(int i=0;i<4;i++)
            a[i]=0;
        int flag=3;
        int temp=result;
        while(temp){
            a[flag--]=temp%10;
            temp=temp/10;
        }
    }while(result!=6174);
    return 0;
}