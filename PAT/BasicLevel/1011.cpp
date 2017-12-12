/**
 * 1011 A+B和C 很傻的一道题　PAT的检测程序真的好烦了!
 */ 
// unsigned   int   0～4294967295   
// int   2147483648～2147483647 
// unsigned long 0～4294967295
// long   -2147483648～2147483647
// long long的最大值：9223372036854775807
// long long的最小值：-9223372036854775808
// unsigned long long的最大值：1844674407370955161
// __int64的最大值：9223372036854775807
// __int64的最小值：-9223372036854775808
// unsigned __int64的最大值：18446744073709551615

#include <iostream>
using namespace std;

void check(long long int*nums,int k){
    if(nums[0]+nums[1]>nums[2]){
        cout<<"Case #"<<k+1<<": true"<<endl;
    }else{
        cout<<"Case #"<<k+1<<": false"<<endl;
    }
}

int main (void){
    int test_count;
    cin >> test_count;
    long long int abc[test_count][3];
    for(int i=0;i<test_count;i++)
        for(int j=0;j<3;j++)
            cin>>abc[i][j];
    
    for(int k=0;k<test_count;k++)
        check(abc[k],k);

    return 0;
}