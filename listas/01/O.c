#include<stdlib.h>
#include<stdio.h>

#define MAX 112345
#define vin(vt, n) for (int i = 0; i < n; i++) scanf(" %d", &vt[i])

int main() {
    int n, m, od[MAX], ev[MAX];
    int j = 0, k = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &m);
        if (m & 1) od[j++] = m;
        else ev[k++] = m;
    }

    for (int i = 0; i < k; i++) {
        if (i != k - 1) printf("%d ", ev[i]);
        else printf("%d\n", ev[i]);
    }

    for (int i = 0; i < j; i++) {
        if (i != j - 1) printf("%d ", od[i]);
        else printf("%d\n", od[i]);
    }

    return 0;
}
