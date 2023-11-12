#ifndef SWAP_LIB
#define SWAP_LIB
#include "swap.h"
#endif
#ifndef MIN_INDEX_LIB
#define MIN_INDEX_LIB
#include "min_index.h"
#endif

void selection_sort_rec(int* arr, int n, int i) {
    if (i == n) return;

    int k = min_index(arr, i, n - 1);
    swap(&arr[i], &arr[k]);
    selection_sort_rec(arr, n, i + 1);
}