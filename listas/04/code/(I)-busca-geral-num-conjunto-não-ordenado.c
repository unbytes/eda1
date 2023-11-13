#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ii {
    int first, second;
} ii;

int binary_search(ii* arr, int n, int t) {
    int l = 0, r = n;

    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m].first == t) return m;
        if (arr[m].first < t) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void merge(ii* arr, int p, int q, int r) {
    ii* z = (ii*)malloc((r - p) * sizeof(ii));

    int i = p, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i].first <= arr[j].first ? arr[i++] : arr[j++];

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = p; i < r; i++)  arr[i] = z[i - p];
    free(z);
}

void merge_sort(ii* arr, int p, int r) {
    if (p >= r - 1) return;

    int q = p + (r - p) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q, r);
    merge(arr, p, q, r);
}

void solve() {
    int n, m, u;
    scanf("%d %d", &n, &m);

    ii arr[n];
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i].first);
        arr[i].second = i;
    }
    merge_sort(arr, 0, n);

    while (m--) {
        scanf(" %d", &u);

        int ans = binary_search(arr, n, u);
        if (ans == -1) printf("%d\n", ans);
        else printf("%d\n", arr[ans].second);
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