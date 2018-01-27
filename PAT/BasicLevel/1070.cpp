// 因为所有长度都要串在一起，每次都等于(旧的绳子长度+新的绳子长度)/2，
// 所以越是早加入绳子长度中的段，越要对折的次数多，所以既然希望绳子长度
// 是最长的，就必须让长的段对折次数尽可能的短。所以将所有段从小到大排序，
// 然后从头到尾从小到大分别将每一段依次加入结绳的绳子中，最后得到的结果
// 才会是最长的结果～

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (void){
    int count;
    vector<int> v;
    int temp;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());
    float sum=(float)(v[0]/2);
    for(int i=1;i<v.size();i++){
        sum=sum/2+(float)v[i]/2;
    }
    cout<<(int)sum<<endl;
    return 0;
}