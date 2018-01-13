#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 bool SortByM1(int v1,int v2){  
    return v1 < v2; 
}  
int main (void){
    int count;
    cin>>count;
    int a[count];
    for(int i=0;i<count;i++)
        cin>>a[i];
    vector<int> v;
    for(int i=0;i<count;i++){
        bool flag1=true;
        bool flag2=true;
        for(int n=0;n<i;n++){
            if(a[n]>a[i]){
                flag1=false;
                break;
            }
        }
        for(int m=count-1;m>i;m--){
            if(a[m]<a[i]){
                flag2=false;
                break;
            }
        }
        if(flag2&&flag1){
            v.push_back(a[i]);
        }
    }


    //对v来个quicksort,然后输出即可
    sort(v.begin(),v.end(),SortByM1);
    size_t size=v.size();
    cout<<size<<endl;
    for(int i=0;i<size-1;i++){
        cout<<v[i]<<" ";
    }

    cout<<v[size];
    return 0;
}