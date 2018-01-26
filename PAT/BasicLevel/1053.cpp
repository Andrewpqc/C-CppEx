/**
 * 住房空置率
 **/
#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    int count, D, empty_num = 0, pro_empty_num = 0;
    float e;
    cin >> count >> e >> D;
    for (int i = 0; i < count; i++){
        int d;
        float temp;  //临时收集输入的电量
        int num = 0; //收集低于阈值的月份数
        cin >> d;

        for (int j = 0; j < d; j++){
            cin >> temp;
            if (temp < e)
                num++;
        }
        if (num > d / 2){
            if (d > D){
                empty_num++;
            }
            else{
                pro_empty_num++;
            }
        }
    }

    float l1 = (float)empty_num / count;
    float l2 = (float)pro_empty_num / count;
    cout << setiosflags(ios::fixed) << setprecision(1) << l1 * 100 << "%"
         << " " << l2 * 100 << "%" << endl;
    return 0;
}