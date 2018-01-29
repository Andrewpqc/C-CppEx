/**
 * 最优找零方案
 * 首先满足大钱,然后满足小钱
 * 下面的小数的除法在计算时存在精度损失
 **/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main (void){
    int count_100,count_50,count_10,count_5,count_2,count_1,count_0_5,count_0_1;
    count_100=0;count_50=0;count_10=0;count_5=0;count_2=0;count_1=0;count_0_5=0;count_0_1=0;
    string s;
    cin>>s;
    size_t pos=s.find('.');
    if(pos==-1){
        //没有小数
        int total=atoi(s.c_str());
        if(total>=100){
            count_100=total/100;
            total=total%100;
        }
        if(total>=50){
            count_50=total/50;
            total=total%50;
        }
        if(total>=10){
            count_10=total/10;
            total=total%10;
        }
        if(total>=5){
            count_5=total/5;
            total=total%5;
        }
        if(total>=2){
            count_2=total/2;
            total=total%2;
        }
        if(total>=1){
            count_1=total;
        }
    }else{
        //有小数
        int part1=atoi(s.substr(0,pos).c_str());
        float part2=atof(("0."+s.substr(pos+1)).c_str());
        // float total=atof(s.c_str());
        // cout<<total<<endl;
        // int part1=(int)total;
        // float part2=total-part1;
        cout<<part2<<endl;
        if(part1>=100){
            count_100=part1/100;
            part1=part1%100;
        }
        if(part1>=50){
            count_50=part1/50;
            part1=part1%50;
        }
        if(part1>=10){
            count_10=part1/10;
            part1=part1%10;
        }
        if(part1>=5){
            count_5=part1/5;
            part1=part1%5;
        }
        if(part1>=2){
            count_2=part1/2;
            part1=part1%2;
        }
        if(part1>=1){
            count_1=part1;
        }

        if(part2>=0.5){
            count_0_5=1;
            part2-=0.5;
        }
        if(part2>=0.1){

            count_0_1=part2/0.1;
        }
    }

    cout<<"找零方案:"<<endl;
    cout<<100<<" "<<50<<" "<<10<<" "<<5<<" "<<2<<" "<<1<<" "<<0.5<<" "<<0.1<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<count_100<<" "<<count_50<<" "<<count_10<<" "<<count_5<<" "<<count_2<<" "<<count_1<<" "<<count_0_5<<" "<<count_0_1<<endl;
    return 0;
}
