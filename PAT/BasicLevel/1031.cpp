/**
 * 身份证校验　1031 部分正确
 **/
#include <iostream>
#include <cctype>
using namespace std;

int main(void){
    int theta[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int code[] = {1, 0, 88, 9, 8, 7, 6, 5, 4, 3, 2}; //88是X的ascii值
    int i;
    cin >> i;
    char ids[i][19];
    for (int j = 0; j < i; j++){
        cin >> ids[j];
    }
    int flag = 0;
    for (int m = 0; m < i; m++){
        int s = 0;
        int flag2 = 0;
        for (int n = 0; n < 17; n++){
            //如果在前17位中出现字符不为数字，那么该身份证肯定有问题
            if (!isdigit(ids[m][n])){
                cout << ids[m] << endl;
                ++flag2;
                ++flag;
                break;
            }
            else{
                int temp = ids[m][n] - '0'; //转化成数字
                s += (temp * theta[n]);
            }
        }
        //校验码不正确

        if (!flag2 && code[s % 11] != ids[m][17] - '0'){
            cout << ids[m] << endl;
            ++flag;
        }
    }
    if (!flag)
        cout << "All passed" << endl;
    return 0;
}