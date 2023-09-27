#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y);
void bubbleSort(int a[], int length);

int main(void){

    int a[] = {1,23,5,373,13,23,1,124,15,2,63};
    int length = 11;

    bubbleSort(a, length);

    for(int i = 0; i < length; i++){
        printf("%d ", a[i]);
    }

    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int a[], int length){

    bool swapped = false;
    int i = 0;

    do{
        swapped = false;

        for(int j = 0; j < (length - 1 - i); j++){
            if( a[j] > a[j + 1] ){
                swap(&a[j], &a[j + 1]);
                swapped = true;
            }
        }
        i++;
    } while (swapped);
}