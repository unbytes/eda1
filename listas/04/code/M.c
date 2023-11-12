#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct pair {
    char first[101], second[101];
} pair;

void merge(pair* arr, int p, int q, int r) {
    pair* z = (pair*)malloc((r - p) * sizeof(pair));

    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        int result = strcmp(arr[i].first, arr[j].first);
        z[k++] = result <= 0 ? arr[i++] : arr[j++];
    }

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = p; i < r; i++)  arr[i] = z[i - p];
}

void merge_sort(pair* arr, int p, int r) {
    if (p >= r - 1) return;

    int q = p + (r - p) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q, r);
    merge(arr, p, q, r);
}

int binary_search(pair* arr, int n, char* t) {
    int l = 0, r = n;

    while (l <= r) {
        int m = (l + r) / 2;

        int result = strcmp(arr[m].first, t);
        if (!result) return m;
        else if (result < 0) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void solve() {
    int m, n;
    scanf("%d %d", &m, &n);

    pair* arr = (pair*)malloc(m * sizeof(pair));
    for (int i = 0; i < m; i++) {
        scanf("\n");
        fgets(arr[i].first, sizeof(arr[i].first), stdin);
        fgets(arr[i].second, sizeof(arr[i].second), stdin);
        arr[i].first[strcspn(arr[i].first, "\n")] = '\0';
        arr[i].second[strcspn(arr[i].second, "\n")] = '\0';
    }

    char line[101];
    merge_sort(arr, 0, m);
    for (int i = 0; i < n; i++) {
        scanf("\n");
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        int k = 0;
        while (true) {
            int j = 0;
            char word[101];
            while (line[k] != ' ' && line[k] != '\0') word[j++] = line[k++];
            word[j] = '\0'; k++;

            int ans = binary_search(arr, m, word);
            if (ans == -1) printf("%s", word);
            else printf("%s", arr[ans].second);

            if (line[k] == '\0') break;
            else printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);

    while (t--) {
        solve();
        printf("\n");
    }

    return 0;
}