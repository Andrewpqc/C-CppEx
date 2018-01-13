/**
 * 划拳
 **/

#include <iostream>
using namespace std;

int main(void){
    int count, jia_cup = 0, yi_cup = 0;
    cin >> count;
    int jiahan;
    int jiahua;
    int yihan;
    int yihua;
    for (int i = 0; i < count; i++){
        cin >> jiahan >> jiahua >> yihan >> yihua;
        if (jiahua == yihua)
            continue;
        if (jiahua == jiahan + yihan)
            yi_cup++;
        if (yihua == jiahan + yihan)
            jia_cup++;
    }
    cout << jia_cup << " " << yi_cup;
    return 0;
}
