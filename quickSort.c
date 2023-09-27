#include <stdio.h>
#include <stdlib.h>

void quickSort(int array[], int length);
void quickSortRecursion(int array[], int low, int high);
void swap(int *x, int *y);
int partition(int array[], int low, int high);

int main(void){
    int array[] = {1,7,4,5,8,92,18,3,1};
    int length = 9;

    quickSort(array, length);

    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    return 0;
}

void quickSort(int array[], int length){
    quickSortRecursion(array, 0, length - 1);
}

void quickSortRecursion(int array[], int low, int high){
    if(low < high){
        int pivotIndex = partition(array, low, high);
        quickSortRecursion(array, low, pivotIndex - 1);
        quickSortRecursion(array, pivotIndex + 1, high);

    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[], int low, int high){
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