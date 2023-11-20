#ifndef SWAP_LIB
#define SWAP_LIB
#include "swap.h"
#endif

int shell_sort(int* arr, int l, int r) {
    int h = 1;
    while (h < r / 3) h = 3 * h + 1;

    for (; h > 0; h /= 3) {
        for (int i = h; i < r; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
                swap(&arr[j], &arr[j - h]);
        }
    }
}