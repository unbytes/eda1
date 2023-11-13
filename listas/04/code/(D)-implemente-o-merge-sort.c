#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "merge_sort.h"

int main() {
    int n;
    scanf(" %d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);

    merge_sort(arr, 0, n);

    for (int j = 0; j < n; j++) {
        printf("%d", arr[j]);
        if (j != n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}