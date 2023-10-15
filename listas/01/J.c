#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

void solve() {
    ll n;
    scanf("%lld", &n);

    for (ll i = 1; i < n + 1; i++) {
        if (i & 1) printf("THUMS THUMS THUMS\n");
        else printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
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