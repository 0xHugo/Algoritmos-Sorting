#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void selectionSort(int a[], int length);

int main(void){

    int a[]  ={5,12,5,6,12,5,67232,51,2,6,15,1};
    int length = 12;

    selectionSort(a, length);

    for(int k = 0; k < length; k++){
        printf("%d ", a[k]);
    }

    return 0;
}

void selectionSort(int a[], int length){
 
    int minPos;
 
    for(int i = 0; i < (length - 1); i++){
        minPos = i;

        for(int j  = i + 1; j < length; j++){
            if(a[j] < a[minPos]) minPos = j;
        }

        if(minPos != i) swap(&a[i], &a[minPos]);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}