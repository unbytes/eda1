#include<stdlib.h>
#include<stdio.h>

#define MAX 112
#define vin(vt, n) for (int i = 0; i < n; i++) scanf(" %d", &vt[i])

int main() {
    int x, y, xs[MAX][MAX], mx = -1;
    scanf("%d %d", &x, &y);

    for (int i = 0; i < x; i++) {
        int tmp = 0;
        for (int j = 0; j < y; j++) {
            scanf(" %d", &xs[i][j]);
            tmp += xs[i][j];
        }
        if (tmp > mx) mx = tmp;
    }

    for (int i = 0; i < y; i++) {
        int tmp = 0;
        for (int j = 0; j < x; j++) tmp += xs[j][i];
        if (tmp > mx) mx = tmp;
    }

    printf("%d\n", mx);

    return 0;
}
