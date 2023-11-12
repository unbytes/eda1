#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000000

typedef long long ll;
typedef struct pair {
    ll* first, second;
} pair;

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

pair* make_unique(ll* arr, ll n) {
    ll* unique = (ll*)malloc(n * sizeof(ll));
    pair* ans = (pair*)malloc(sizeof(pair));
    ans->first = unique;
    ans->second = n;
    if (n == 1) return ans;

    ll j = 0;
    unique[j] = arr[j];
    for (ll i = 0; i < n - 1; i++) if (arr[i] != unique[j]) unique[++j] = arr[i];
    ans->second = ++j;

    return ans;
}

ll binary_search(ll* arr, ll n, ll t) {
    ll l = 0, r = n;

    while (l <= r) {
        ll m = (l + r) / 2;

        if (arr[m] == t) return m;
        else if (arr[m] < t) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void solve() {
    ll n;
    scanf("%lld", &n);

    ll arr[n + 1];
    for (ll i = 0; i < n; i++) scanf("%lld", &arr[i]);
    merge_sort(arr, 0, n);

    pair* ans = make_unique(arr, n + 1);
    if (ans->second % 2) ans->first[ans->second++] = MAX;

    ll j = 0;
    ll* added = (ll*)malloc(ans->second * sizeof(ll));
    for (ll i = 1; i < ans->second; i += 2) {
        ll result = ans->first[i - 1] + ans->first[i];
        if (binary_search(ans->first, ans->second, result) == -1) added[j++] = result;
    }

    ll k = 0, l = 0, m = 0, tot = j + ans->second;
    ll* joined = (ll*)malloc(tot * sizeof(ll));
    while (k < j && l < ans->second) {
        if (ans->first[l] <= added[k]) joined[m] = ans->first[l++];
        else joined[m] = added[k++];
        m++;
    }

    while (k < j) joined[m++] = added[k++];
    while (l < ans->second) joined[m++] = ans->first[l++];

    for (ll i = 0; i < tot; i += 4) printf("%lld\n", joined[i]);
    printf("Elementos: %lld\n", tot);
}

int main() {
    ll t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}