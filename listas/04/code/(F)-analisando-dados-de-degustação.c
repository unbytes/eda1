#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100010

typedef struct tuple {
    int a, b;
    char c;
} tuple;

void merge(tuple* arr, int p, int q, int r) {
    tuple* z = (tuple*)malloc((r - p) * sizeof(tuple));

    int i = p, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i].a >= arr[j].a ? arr[i++] : arr[j++];

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = p; i < r; i++)  arr[i] = z[i - p];
    free(z);
}

void merge_sort(tuple* arr, int p, int r) {
    if (p >= r - 1) return;

    int q = p + (r - p) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q, r);
    merge(arr, p, q, r);
}

void solve() {
    tuple counter[MAX];
    char string[MAX];
    scanf("%s", string);

    int ln = 0, i = 0, j = 0, n = 0;
    char prev = string[0];
    char* ch = &string[0];
    while (*ch != '\0') {
        for (; *ch == prev; ch++, ln++);

        tuple info = { .a = ln, .b = j, .c = *(ch - 1) };
        counter[i++] = info;

        j += ln;
        ln = 0; n++; prev = *ch;
    }

    merge_sort(counter, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d %c %d\n", counter[i].a, counter[i].c, counter[i].b);
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}