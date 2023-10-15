#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

void solve() {
    int n, c, s, e, tot = 0, ans = 0;

    scanf("%d %d", &n, &c);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &e);
        tot -= s;
        tot += e;

        if (tot > c) ans = 1;
    }

    if (ans) printf("S\n");
    else printf("N\n");
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}