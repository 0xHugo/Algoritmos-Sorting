#include <stdio.h>

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