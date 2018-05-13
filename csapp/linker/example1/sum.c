int sum(int* a,int size){
    int i,s=0;
    for(i=0;i<size;i++)
        s+=a[i];
    return s;
}