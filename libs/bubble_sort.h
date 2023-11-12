#ifndef SWAP_LIB
#define SWAP_LIB
#include "swap.h"
#endif

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) swap(&arr[j - 1], &arr[j]);
        }
    }
}