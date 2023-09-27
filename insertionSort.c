#include <stdio.h>

void insertionSort(int a[], int length);


int main(void){
    int a[] = {8,21,4,6,37,25,51,734,112,23,132,1};
    int length = 12;
    
    insertionSort(a, length);

    for(int i = 0; i < length; i++){
        printf("%d ", a[i]);
    }

    return 0;
}

void insertionSort(int a[], int length){
    for(int i = 1; i < length; i++){
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j -= 1; 
        }
        a[j + 1] = key;

    }
}