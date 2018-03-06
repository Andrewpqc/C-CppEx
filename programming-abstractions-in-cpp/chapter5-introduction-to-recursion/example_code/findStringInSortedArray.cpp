//二分查找
#include <iostream>
using namespace std;

size_t findStringInSortedArray(string key,string arrray[],int n);
size_t binarySearch(string key,string array[],int low,int high);

int main (void){
    string a[3]={"aaa","bbb","ccc"};
    cout<<findStringInSortedArray("bb",a,3)<<endl;
    return 0;
}


size_t findStringInSortedArray(string key,string array[],int n){
    return binarySearch(key,array,0,n-1);
}

size_t binarySearch(string key,string array[],int low,int high){
    if (low>high) return -1;
    int mid=(low+high)/2;
    if(array[mid]==key)
        return mid;
    else if(array[mid]>key){
        return binarySearch(key,array,low,mid-1);
    }else{
        return binarySearch(key,array,mid+1,high);
    }
}