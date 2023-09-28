#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"

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
