#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

void solve() {
    int n, c, p = __INT_MAX__, idx = -1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &c);

        if (c < p) {
            p = c;
            idx = i;
        }
    }
    printf("%d\n", idx);
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}