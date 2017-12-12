/**
 * 1012 数字分类　部分正确，段错误　真的找不出来哪里段错误了，哥哥。
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(void){
    int count;
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    float A4 = 0.0;
    vector<int> A2_array;
    vector<int> A4_array;
    vector<int> A5_array;
    cin >> count;
    // int nums[count];其实不需要，直接循环就行了
    for (int i = 0; i < count; i++){
        int t;
        cin >> t;
        if (t != 0 && t % 10 == 0)
            A1 += t;
        int remain = t % 5;
        if (remain == 1)
            A2_array.push_back(t);
        if (remain == 2)
            ++A3;
        if (remain == 3)
            A4_array.push_back(t);
        if (remain == 4)
            A5_array.push_back(t);
    }
    //求A2
    for (int i = 0; i < A2_array.size(); i++){
        if (i % 2 == 0)
            A2 += A2_array[i];
        else
            A2 -= A2_array[i];
    }
    //求A4
    A4 = static_cast<float>(accumulate(A4_array.begin(), A4_array.end(), 0)) / A4_array.size();
    //求A5
    A5 = *max_element(A5_array.begin(), A5_array.end());
    //输出 PAT就是麻烦啊
    if (A1)
        cout << A1 << " ";
    else
        cout << 'N' << " ";

    if (A2)
        cout << A2 << " ";
    else
        cout << 'N' << " ";

    if (A3)
        cout << A3 << " ";
    else
        cout << "N"
             << " ";

    if (A4_array.size())
        cout << fixed << setprecision(1) << A4 << " ";
    else
        cout << 'N' << " ";

    if (A5)
        cout << A5;
    else
        cout << 'N';

    return 0;
}