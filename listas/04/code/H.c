#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lower_bound.h"

void solve() {
    int n, m, u;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (m--) {
        scanf("%d", &u);

        int ans = lower_bound(arr, n, u);
        printf("%d\n", ans);
    }
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}