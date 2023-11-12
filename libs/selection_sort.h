#include "swap.h"

void selection_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int* el = &arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < *el) el = &arr[j];
        }
        swap(el, &arr[i]);
    }
}