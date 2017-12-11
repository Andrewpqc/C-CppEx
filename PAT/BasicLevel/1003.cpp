/**
 * 1003 我要通过，感觉题目输入输出样例有问题
 */

#include <iostream>
#include <cstdlib>
using namespace std;
void check(char* a){
    bool flag=false;
    int P_count=0,T_count=0,P_position=-1,T_position=-1,A_count=0;
    //该字符串含有PAT以外的字符，直接NO,退出程序
    for(int i=0;a[i]!='\0';i++){
        if(a[i]!='P'&&a[i]!='A'&&a[i]!='T'){
            cout<<"NO"<<endl;
            flag=true;
            break;
        }

        // 2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
        // 3. 如果aPbTc是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
        
        
        //上面两条说明，该字符串中必须有一个P,一个T,并且P出现在T的前面，A可以有1个或多个
        
        if(a[i]=='P'){
            ++P_count;
            P_position=i;
        }
        if(a[i]=='A'){
            ++A_count;
        }
        if(a[i]=='T'){
            ++T_count;
            T_position=i;
        }

        
    }
    if(T_count!=1||P_count!=1||T_position<P_position||A_count==0){
        cout<<"NO"<<endl;
        flag=true;
    }
    if(!flag){
        cout<<"YES"<<endl;
    }
}
int main (void){
    int count;
    cin>>count;
    char strs[10][100];
    for(int j=0;j<count;j++){
        cin>>strs[j];
    }
    for(int i=0;i<count;i++){
        check(strs[i]);
    }
    return 0;
}
