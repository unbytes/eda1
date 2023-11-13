#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pair {
    int first;
    char second[17];
} pair;

void merge(pair* arr, int p, int q, int r) {
    pair* z = (pair*)malloc((r - p) * sizeof(pair));

    int i = p, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i].first <= arr[j].first ? arr[i++] : arr[j++];

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = p; i < r; i++)  arr[i] = z[i - p];
    free(z);
}

void merge_sort(pair* arr, int p, int r) {
    if (p >= r - 1) return;

    int q = p + (r - p) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q, r);
    merge(arr, p, q, r);
}

int binary_search(pair* arr, int n, int t) {
    int l = 0, r = n;

    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m].first == t) return m;
        else if (arr[m].first < t) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void solve() {
    int n, m;
    scanf("%d", &n);

    pair* arr = (pair*)malloc(n * sizeof(pair));
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].first, arr[i].second);
    }

    merge_sort(arr, 0, n);
    while (scanf("%d", &m) != EOF) {
        int ans = binary_search(arr, n, m);

        if (ans == -1) printf("undefined\n");
        else printf("%s\n", arr[ans].second);
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