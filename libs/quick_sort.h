#ifndef SWAP_LIB
#define SWAP_LIB
#include "swap.h"
#endif

int partition(int* arr, int l, int r) {
    int pivot = arr[r], j = l;

    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) swap(&arr[i], &arr[j++]);
    }
    swap(&arr[j], &arr[r]);

    return j;
}

void quick_sort(int* arr, int l, int r) {
    if (l > r) return;

    int p = partition(arr, l, r);
    quick_sort(arr, l, p - 1);
    quick_sort(arr, p + 1, r);
}