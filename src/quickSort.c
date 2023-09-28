#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "auxiliar.h"
#include "quickSort.h"

void quickSort(int array[], int length){

    srand(time(NULL));
    quickSortRecursion(array, 0, length - 1);
}

void quickSortRecursion(int array[], int low, int high){
    if(low < high){
        int pivotIndex = partition(array, low, high);
        quickSortRecursion(array, low, pivotIndex - 1);
        quickSortRecursion(array, pivotIndex + 1, high);

    }
}

int partition(int array[], int low, int high){

    int pivotIndex = low + (rand() % (high-low));

    if(pivotIndex != high) swap(&array[pivotIndex], &array[high]);

    int pivotValue = array[high];
    int i = low;

    for(int j = low; j < high; j++){
        if( array[j] <= pivotValue ){
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);
    return i;
}