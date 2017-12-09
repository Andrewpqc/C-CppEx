/**
 * 将两个有序数组合并并且保持合并之后之后数组依然有序
 */ 
#include <stdio.h>
#include <stdlib.h>
void mergeAndSort(int *sequence1, int count1, int *sequence2, int count2, int *afterSort){
    int i, j, flag = 0;
    while ((i != count1) && (j != count2)){
        if (sequence1[i] < sequence2[j]){
            afterSort[flag++] = sequence1[i++];
        }
        else if (sequence1[i] == sequence2[j]){ //防止漏掉最后一个相等的情况
            afterSort[flag++] = sequence1[i++];
            afterSort[flag++] = sequence2[j++];
        }
        else{
            afterSort[flag++] = sequence2[j++];
        }
    }

    //多出来的元素直接放入
    if (count1 == i){
        while (j < count2){
            afterSort[flag++] = sequence2[j++];
        }
    }
    else if (count2 == j){
        while (i < count1){
            afterSort[flag++] = sequence1[i++];
        }
    }
}

int main(void){
    int count1, count2, i;
    printf("Please enter the count of ordered sequence1:");
    scanf("%d", &count1);
    int sequence1[count1];
    for (int i = 0; i < count1; i++){
        printf("\nEnter %d number of sequence1:", i + 1);
        scanf("%d", &sequence1[i]);
    }

    printf("\nPlease enter the count of ordered sequence2:");
    scanf("%d", &count2);
    int sequence2[count2];
    for (int i = 0; i < count2; i++){
        printf("\nEnter %d number of sequence2:", i + 1);
        scanf("%d", &sequence2[i]);
    }

    int afterSort[count1 + count2];
    mergeAndSort(sequence1, count1, sequence2, count2, afterSort);
    printf("After sort:\n");
    for (i = 0; i < (count1 + count2); i++){
        printf("%d ", afterSort[i]);
    }
    return 0;
}