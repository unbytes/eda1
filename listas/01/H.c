#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

ll t = 1;
void solve(ll n) {
    ll x, y;

    ll a = 0, b = 0;
    for (ll i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        a += x;
        b += y;
    }

    printf("Teste %lld\n", t++);
    if (b > a) printf("Beto\n\n");
    else printf("Aldo\n\n");
}

int main() {
    //int t = 1;
    //scanf("%d", &t);

    while (1) {
        ll n;
        scanf("%lld", &n);

        if (n == 0) break;
        solve(n);
    }

    return 0;
}