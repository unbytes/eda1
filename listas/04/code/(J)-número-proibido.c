#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define vin(vt, n) for (ll i = 0; i < n; i++) scanf(" %lld", &vt[i])

typedef long long ll;
typedef struct pll {
    ll first, second;
} pll;

pll binary_search(ll* arr, ll n, ll t) {
    ll l = 0, r = n;
    pll ans = { false, -1 };

    while (l <= r) {
        ll m = (l + r) / 2;

        if (arr[m] == t) {
            pll ans = { true, m };
            return ans;
        }
        else if (arr[m] < t) l = m + 1;
        else r = m - 1;
    }

    return ans;
}

void merge(ll* arr, ll p, ll q, ll r) {
    ll* z = (ll*)malloc((r - p) * sizeof(ll));

    ll i = p, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = p; i < r; i++)  arr[i] = z[i - p];
    free(z);
}

void merge_sort(ll* arr, ll p, ll r) {
    if (p >= r - 1) return;

    ll q = p + (r - p) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q, r);
    merge(arr, p, q, r);
}

void solve() {
    ll n, m;
    scanf(" %lld", &n);

    ll arr[n];
    vin(arr, n);
    merge_sort(arr, 0, n);

    while (scanf(" %lld", &m) != EOF) {
        pll ans = binary_search(arr, n, m);
        if (ans.first) printf("sim\n");
        else printf("nao\n");
    }
}

int main() {
    ll t = 1;
    //scanf("%lld", &t);

    while (t--) {
        solve();
    }

    return 0;
}