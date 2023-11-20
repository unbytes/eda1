#ifndef SWAP_LIB
#define SWAP_LIB
#include "swap.h"
#endif
#ifndef QUICK_SORT_LIB
#define QUICK_SORT_LIB
#include "quick_sort.h"
#endif

void quick_sort_median(int* arr, int l, int r) {
    if (l > r) return;

    int m = l + (r - l) / 2;
    if (arr[m] < arr[l]) swap(&arr[m], &arr[l]);
    if (arr[r] < arr[l]) swap(&arr[l], &arr[r]);
    if (arr[m] < arr[r]) swap(&arr[r], &arr[m]);

    int p = partition(arr, l, r);
    quick_sort_median(arr, l, p - 1);
    quick_sort_median(arr, p + 1, r);
}