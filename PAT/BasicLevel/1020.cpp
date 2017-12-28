#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
using namespace std;
typedef struct Node{
    int kucun;
    float price;
}Kindy;

//按照价格从大到小排序
int mycompare(const void *p1,const void *p2){
    const Kindy * a1=(const Kindy*)p1;
    const Kindy * a2=(const Kindy*)p2;
    if(a1->price>a2->price)
        return -1;
    else if (a1->price==a2->price)
        return 0;
    else 
        return 1; 
}
int main (void){
    int kind_num,need_num;
    cin>>kind_num>>need_num;
    int kucun[kind_num];
    int xiaoliang[kind_num];
    for(int i=0;i<kind_num;i++)
        cin>>kucun[i];
    for(int j=0;j<kind_num;j++)
        cin>>xiaoliang[j];
    Kindy kindymsgs[kind_num];
    for(int i=0;i<kind_num;i++){
        kindymsgs[i].kucun=kucun[i];
        kindymsgs[i].price=(float)xiaoliang[i]/kucun[i];
    }
    
    qsort(kindymsgs,kind_num,sizeof(Kindy),mycompare);
    float sum=0.0;
    for(int i=0;i<kind_num;i++){
        if(need_num>=kindymsgs[i].kucun){
            sum+=kindymsgs[i].kucun*kindymsgs[i].price;
            need_num-=kindymsgs[i].kucun;
        }
        else if(need_num<kindymsgs[i].kucun){
            sum+=need_num*kindymsgs[i].price;
            break;
        }
    }
    printf("%.2f",sum);
    return 0;
}