#include <iostream>  
#include <vector>  
#include <algorithm>  
    
using namespace std;  
    
int m , n;  
    
void Findmn(int N){  
    int i , j;  
    for(i = 2 ; i * i <= N ; i++){  
        if(N % i == 0){  
            j = N / i;  
            if(abs(m - n) > abs (i - j)){  
                m = max(i , j);  
                n = min(i , j);  
            }  
        }  
    }  
}  
    
bool cmp(int a , int b){  
    return a > b;  
}  
    
int main(void){  
    int N;  
    cin>>N;  
    vector<int> Nums(N);  
    int i,j;  
    for(i = 0 ; i < N ; i++)  
        cin>>Nums[i];  
    sort(Nums.begin(),Nums.end(),cmp);  
    m = N;  
    n = 1;  
    Findmn(N);  
    vector<vector<int> > W(m);  
    for(i = 0 ; i < m ; i++)  
        W[i].assign(n,0);  
    int m1 = m -1, n1 = n , m2 , n2;  
    vector<int> dx(N),dy(N);  
    i = 0;  
    if(N == 1)  
        cout<<Nums[0]<<endl;  
    else{  
        while(n1){  
            n2 = n1;  
            while(n2--){  
                dx[i] = 0;  
                dy[i++] = 1;  
            }  
            n1--;  
            m2 = m1;  
            while(m2--){  
                dx[i] = 1;  
                dy[i++] = 0;  
            }  
            m1--;  
            if(n1 == 0)  
                break;  
            n2 = n1;  
            while(n2--){  
                dx[i] = 0;  
                dy[i++] = -1;  
            }  
            n1--;  
            m2 = m1;  
            while(m2--){  
                dx[i] = -1;  
                dy[i++] = 0;  
            }  
            m1--;  
        }  
        int x1 = 0 , y1 = -1;  
        for(i = 0 ; i < N ; i ++){  
            x1 += dx[i];  
            y1 += dy[i];  
            W[x1][y1] = Nums[i];  
        }  
        for(i = 0 ; i < m ; i++){  
            cout<<W[i][0];  
            for(j = 1 ; j < n ; j++){  
                cout<<' '<<W[i][j];  
            }  
            cout<<endl;  
        }  
    } 

    return 0;  
}  