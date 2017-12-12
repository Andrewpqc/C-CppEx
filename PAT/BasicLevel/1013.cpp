/**
 * 1013 数素数 运行超时，这一次终于知道为什么错了
 */ 
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(void){
//     int M,N;
//     cin>>M>>N;
//     vector<int> primeNums;
//     int flag;
//     primeNums.push_back(2);
//     int prime_nums_count=1;
//     for (int i = 3; ; i++){
//         flag = 0;
//         for (int j = 2; j * j <= i; j++){
//             if (i % j == 0){
//                 ++flag;
//             }
//         }
//         if (flag == 0){
//             primeNums.push_back(i);
//             ++prime_nums_count;
//         }
//         if(prime_nums_count==40000)
//             break;
//     }

//     for(int j=1, i=M;i<=N;i++,j++){
//         cout<<primeNums[i-1]<<" ";
//         if(j%10==0)   
//             cout<<endl;
//     }
//     return 0;
// }

//上面注释的代码运行超时，下面重写,这个答案错误,这又有什么错误啊
#include <iostream>
using namespace std;
int main (void){
    int M,N;
    cin>>M>>N;
    int flag,flag2=0;
    int prime_nums_count=1;
    if (M==1){
        cout<<2<<" ";
        flag2=1;
    }
    for (int i = 3; ; i++){
        flag = 0;
        for (int j = 2; j * j <= i; j++){
            if (i % j == 0){
                ++flag;
            }
        }
        if (flag == 0){
            ++prime_nums_count;
            if(prime_nums_count>=M && prime_nums_count<=N){
                cout<<i<<" ";
                ++flag2;
                if(flag2%10==0)
                    cout<<endl;
            }
            if(prime_nums_count>N)
                break;
        }
    }
    cout<<'\b';
    return 0;
}