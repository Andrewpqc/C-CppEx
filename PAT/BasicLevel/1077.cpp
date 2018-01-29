#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(void)
{
    size_t count, edge;
    vector<vector<int> > V;
    vector<int> teacher_v;
    int temp;
    cin >> count >> edge;
    for (int i = 0; i < count; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < count; j++)
        {
            cin >> temp;
            if (j == 0)
            {
                teacher_v.push_back(temp);
            }
            else
            {
                if (temp >= 0 && temp <= 50)
                {
                    tmp.push_back(temp);
                }
            }
        }
        V.push_back(tmp);
    }
    for (int i = 0; i < count; i++)
    {
        sort(V[i].begin(), V[i].end());
        V[i].erase(V[i].begin());
        V[i].erase(V[i].end() - 1);
        float average = (float)accumulate(V[i].begin(), V[i].end(), 0) / V[i].size();
        float mid_result = (average + teacher_v[i]) / 2;
        int mid_result_int = (int)mid_result;
        float remain = mid_result - mid_result_int;
        int end_result = (remain >= 0.5) ? mid_result_int + 1 : mid_result_int;
        cout << end_result << endl;
    }

    return 0;
}