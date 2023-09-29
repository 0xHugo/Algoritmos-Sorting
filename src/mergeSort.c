#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"

void mergeSort(int a[], int length){
    mergeSortRecursion(a, 0, length - 1);
}

void mergeSortRecursion(int a[], int l, int r){
    
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSortRecursion(a, l, m);
        mergeSortRecursion(a, m+1, r);

        mergeSortedArrays(a,l,m,r);
    }
}

void mergeSortedArrays(int a[], int l, int m, int r){
    int leftLength = m - l + 1;
    int rightLength = r - m;

    int tempLeft[leftLength];
    int tempRight[rightLength];

    int i,j,k;

    for(int i = 0; i < leftLength; i++){
        tempLeft[i] = a[l + i];
    }

    for(int i = 0; i < rightLength; i++){
        tempRight[i] = a[m + 1 + i];
    }

    for(i = 0, j = 0, k = l; k<=r; k++){
        if((i < leftLength) && (j >= rightLength || tempLeft[i] <= tempRight[j])){
            a[k] = tempLeft[i];
            i++;
        }else{
            a[k] = tempRight[j];
            j++;
        }
    }
}
