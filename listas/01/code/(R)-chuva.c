#include<stdlib.h>
#include<stdio.h>

#define MAX 112
#define vin(vt, n) for (int i = 0; i < n; i++) scanf(" %d", &vt[i])

int main() {
    int n, xs[MAX][MAX], ys[MAX][MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %d", &xs[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %d", &ys[i][j]);
            ys[i][j] += xs[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - 1) printf("%d ", ys[i][j]);
            else printf("%d\n", ys[i][j]);
        }
    }

    return 0;
}
