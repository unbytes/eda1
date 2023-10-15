#include<stdlib.h>
#include<stdio.h>

#define MAX 1123456
#define vin(vt, n) for (int i = 0; i < n; i++) scanf(" %d", &vt[i])

int main() {
    int n, m, xs[MAX];

    scanf("%d", &n);
    vin(xs, n);
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        if (xs[i] == m) {
            printf("pertence\n");
            return 0;
        }
    }
    printf("nao pertence\n");

    return 0;
}
