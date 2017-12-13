/**
 * 1016 部分A+B 终于又通过了一道题目，感动到流泪
 */
#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    char A[11];
    char B[11];
    char DA, DB;
    int DA_count = 0, DB_count = 0, sum_A = 0, sum_B = 0;
    cin >> A >> DA >> B >> DB;
    for (int i = 0; A[i] != '\0'; i++)
        if (A[i] == DA)
            DA_count++;

    for (int i = 0; B[i] != '\0'; i++)
        if (B[i] == DB)
            DB_count++;

    for (int i = 0; i < DA_count; i++)
        sum_A += pow(10, i) * (static_cast<int>(DA) - 48);

    for (int i = 0; i < DB_count; i++)
        sum_B += pow(10, i) * (static_cast<int>(DB) - 48);
        
    cout << sum_A + sum_B;
    return 0;
}