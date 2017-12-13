/**
 * 1002写出这个数　感觉此题有问题
 * 明明没问题啊，通过不了测试啊
 */
#include <iostream>
using namespace std;
void print(int i){
     switch(i){
            case 0:
                cout<<"ling"<<" ";
                break;
            case 1:
                cout<<"yi"<<" ";
                break;
            case 2:
                cout<<"er"<<" ";
                break;
            case 3:
                cout<<"san"<<" ";
                break;
            case 4:
                cout<<"si"<<" ";
                break;
            case 5:
                cout<<"wu"<<" ";
                break;
            case 6:
                cout<<"liu"<<" ";
                break;
            case 7:
                cout<<"qi"<<" ";
                break;
            case 8:
                cout<<"ba"<<" ";
                break;
            case 9:
                cout<<"jiu"<<" ";
                break;
        }
}

int main (void){
    int sum=0;
    char fake_bits[101];
    cin>>fake_bits;
    // for(int i=0;i<100;i++){
    //     switch(fake_bits[i]){
    //         case '1':
    //             sum+=1;
    //             break;
    //         case '2':
    //             sum+=2;
    //             break;
    //         case '3':
    //             sum+=3;
    //             break;
    //         case '4':
    //             sum+=4;
    //             break;
    //         case '5':
    //             sum+=5;
    //             break;
    //         case '6':
    //             sum+=6;
    //             break;
    //         case '7':
    //             sum+=7;
    //             break;
    //         case '8':
    //             sum+=8;
    //             break;
    //         case '9':
    //             sum+=9;
    //             break;
    //         default:
    //             sum+=0;
    //     }
    // }


    //上面这种求sum的方法太low,可以利用相同的数字与字符ascii之间对应的对应关系
    for(int i=0;fake_bits[i]!='\0';i++){
        sum+=(int)(fake_bits[i]-48);
    }
    //根据题意可知，sum的最大值为9900,最多的位数为４位
    int bits[4]={0};
    int bit,newNum,flag=0;
    bit = sum % 10;
    newNum = sum / 10;
    bits[0] = bit;
    while (newNum){
        bit = newNum % 10;
        newNum = newNum / 10;
        bits[++flag] = bit;
    }
    for(int j=flag;j>=0;j--){
            print(bits[j]);
    }
    //为了通过黑箱测试，去掉最后一个空格
    cout<<"\b";
    return 0;
}
