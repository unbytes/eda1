#ifndef MIN_INDEX_LIB
#define MIN_INDEX_LIB
#include "min_index.h"
#endif

int min(int* arr, int n) {
    return arr[min_index(arr, 0, n - 1)];
}