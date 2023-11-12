#include "swap.h"
#include "min_index.h"

void selection_sort_rec(int* arr, int n, int i) {
    if (i == n) return;

    int k = min_index(arr, i, n - 1);
    swap(&arr[i], &arr[k]);
    selection_sort_rec(arr, n, i + 1);
}