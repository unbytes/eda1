#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "merge_sort.h"

void solve() {
    int n;
    scanf(" %d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);

    merge_sort(arr, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}