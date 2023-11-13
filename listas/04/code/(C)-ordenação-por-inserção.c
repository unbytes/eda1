#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "insertion_sort.h"

#define MAX 50001

int main() {
    int arr[MAX];

    int i = 0;
    while (scanf("%d ", &arr[i++]) != EOF);

    insertion_sort(arr, --i);

    for (int j = 0; j < i; j++) printf("%d ", arr[j]);
    printf("\n");

    return 0;
}