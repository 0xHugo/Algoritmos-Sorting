#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "auxiliar.h"

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