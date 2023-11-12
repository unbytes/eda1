#include "min_index.h"

int min(int* arr, int n) {
    return arr[min_index(arr, 0, n - 1)];
}