/**
 * 1014 福尔莫斯的约会 答案错误　我已经不对PAT的检测程序不报任何希望了。
 */ 

/**
 * ASCII:
 * A 65
 * Z 90 
 * a 97
 * z 122
 */
#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    char Day,H;
    int M;
    char passwords[4][60];
    for(int i=0;i<4;i++)
        cin >> passwords[i];
    
    int length1=strlen(passwords[0]);
    int length2=strlen(passwords[1]);
    int length3=strlen(passwords[2]);
    int length4=strlen(passwords[3]);

    int group1_min=(length1<length2)?length1:length2;
    int group2_min=(length3<length4)?length3:length4;

    //找出包含Day,H的信息的字母
    bool flag=true;
    for(int i=0;i<group1_min;i++){
        if(passwords[0][i] == passwords[1][i]){
            if(flag &&'A' <= passwords[0][i] && passwords[0][i] <= 'Z'){
                cout<<"Day"<<passwords[0][i];
                Day=passwords[0][i];
                flag=false;
            }
            else if(!flag){
                H=passwords[0][i];
                break;
            } 
        }        
    }

    //找出包含M信息的数字
    for(int j=0;j<group2_min;j++){
        if(passwords[2][j]==passwords[3][j]){
            if((65<=passwords[2][j]&&90>=passwords[2][j])||(97<=passwords[2][j]&&122>=passwords[2][j])){
                M=j;
                break;
            }
        }
    }
    
    cout<<"信息"<<Day<<H<<M<<endl;
    //解析Day 使用傻逼解析法
    if(Day=='A')
        cout<<"MON"<<" ";
    else if(Day=='B')
        cout<<"TUE"<<" ";
    else if(Day=='C')
        cout<<"WED"<<" ";
    else if(Day=='D')
        cout<<"THU"<<" ";
    else if(Day=='E')
        cout<<"FRI"<<" ";
    else if(Day=='F')
        cout<<"SAT"<<" ";
    else if(Day=='G')
        cout<<"SUN"<<" ";
    

    //解析H
    if('0'<=H&&H<='9'){
        cout<<0<<H<<':';
    }
    else if('A'<=H&&H<='N'){
        int h=static_cast<int>(H)-55;
        cout<<h<<':';
    }

    //解析M
    if(0<=M&&M<=9){
        cout<<'0'<<M;
    }

    return 0;
}