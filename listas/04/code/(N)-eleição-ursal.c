#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef struct pair {
    ll code, votes;
} pair;

void merge(pair* arr, int p, int q, int r) {
    pair* z = (pair*)malloc((r - p) * sizeof(pair));

    int i = p, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i].votes <= arr[j].votes ? arr[i++] : arr[j++];

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

void solve() {
    ll s, f, e, m, valid = 0, invalid = 0;
    scanf("%lld %lld %lld", &s, &f, &e);

    pair* hash = (pair*)malloc(99991 * sizeof(pair));
    for (ll i = 0; i < 99991; i++) hash[i].code = i + 10;
    while (scanf("%lld", &m) != EOF) {
        if (m >= 10) {
            hash[m - 10].votes++;
            valid++;
        }
        else invalid++;
    }

    merge_sort(hash, 0, 90);
    merge_sort(hash, 90, 990);
    merge_sort(hash, 990, 9990);
    merge_sort(hash, 9990, 99990);

    ll votes = 0;
    for (ll i = 89; i >= 0 && s; i--) votes += hash[i].votes;

    printf("%lld %lld\n", valid, invalid);

    if ((float)hash[89].votes / (float)votes >= 0.51) printf("%lld\n", hash[89].code);
    else  printf("Segundo turno\n");

    for (ll i = 989; i >= 90 && s; i--, s--) printf("%lld ", hash[i].code);
    printf("\n");
    for (ll i = 9989; i >= 990 && f; i--, f--) printf("%lld ", hash[i].code);
    printf("\n");
    for (ll i = 99989; i >= 9990 && e; i--, e--) printf("%lld ", hash[i].code);
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