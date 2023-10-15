#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 11234

typedef long long ll;

int ps = 1;
void solve(ll a, ll c) {
    ll x, y, xs[MAX];

    for (ll i = 0; i < a; i++) xs[i] = 0;

    for (ll i = 0; i < c; i++) {
        scanf("%lld %lld", &x, &y);
        xs[x - 1] += 1;
        xs[y - 1] += 1;
    }

    ll mx = -1;
    for (ll i = 0; i < a; i++) {
        if (xs[i] > mx) mx = xs[i];
    }

    ll ans = 0;
    for (ll i = 0; i < a; i++) {
        if (xs[i] == mx) ans++;
    }

    printf("Teste %d\n", ps++);
    for (ll i = 0; i < a; i++) {
        if (xs[i] == mx) {
            ans--;
            if (ans != 0) printf("%lld ", i + 1);
            else printf("%lld\n\n", i + 1);
        }
    }
}

int main() {
    //int t = 1;
    //scanf("%d", &t);

    while (true) {
        ll a, c;
        scanf("%lld %lld", &a, &c);

        if (a == 0 && c == 0) break;

        solve(a, c);
    }

    return 0;
}