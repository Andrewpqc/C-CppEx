/**
 * 归并还是插入 暂时没有搞定
 **/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void print(int *a, size_t size){
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}

bool is_eq(int *a, int *b, size_t size){
    int flag = true;
    for (int i = 0; i < size; i++)
        if (a[i] != b[i])
            flag = false;
    if (flag)
        return true;
    else
        return false;
}

bool is_insert_sort(int *a, int *mid, size_t size){
    int flag = 0;
    //查看初始状态是否相同
    if (is_eq(a, mid, size))
        flag = 1;

    for (int i = 1; i < size; i++){
        if (a[i - 1] > a[i]){
            int temp = a[i];
            int j = i;
            do{
                a[j] = a[j - 1];
                --j;
            } while (j > 0 && a[j - 1] > temp);
            a[j] = temp;
        }
        if (flag == i){
            cout << "Insertion Sort" << endl;
            print(a, size);
            return true;
        }
        //这是迭代之后的情况
        if (is_eq(a, mid, size))
            flag = i + 1;
    }
    return false;
}

void merge_sort(int *list, int length){
    int i, left_min, left_max, right_min, right_max, next;
    int *tmp = (int *)malloc(sizeof(int) * length);
    
    // i为步长，1,2,4,8……
    for (i = 1; i < length; i *= 2) {
        for (left_min = 0; left_min < length - i; left_min = right_max){
            right_min = left_max = left_min + i;
            right_max = left_max + i;

            if (right_max > length)
                right_max = length;

            next = 0;
            while (left_min < left_max && right_min < right_max)
                tmp[next++] = list[left_min] > list[right_min] ? list[right_min++] : list[left_min++];

            while (left_min < left_max)
                list[--right_min] = list[--left_max];

            while (next > 0)
                list[--right_min] = tmp[--next];
        }
    }
    free(tmp);
}

int main(void)
{
    // int count;
    // cin>>count;
    // int origin[count];//接收原始序列
    // int middle[count];//接收中间序列
    // for(int i=0;i<count;i++)
    //     cin>>origin[i];

    // for(int i=0;i<count;i++)
    //     cin>>middle[i];

    int a[5] = {2, 5, 3, 4, 2};
    int mid[5] = {2, 3, 5, 4, 2};
    is_insert_sort(a, mid, 5);
    // for(int i=0;i<5;i++)
    //     cout<<a[i]<<" ";
    return 0;
}