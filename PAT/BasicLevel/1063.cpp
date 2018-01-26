#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main (void){
    size_t count;
    cin>>count;
    double max;
    int a,b;
    cin>>a>>b;
    max=sqrt(a*a+b*b);
    for(int i=0;i<count-1;i++){
        cin>>a>>b;
        double temp=sqrt(a*a+b*b);
        if(temp>max){
            max=temp;
        }
    }

    cout<<setiosflags(ios::fixed) << setprecision(2)<<max<<endl;




    return 0;
}