#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solve(int n) {
    if (n >= 101) return n - 10;

    return solve(solve(n + 11));
}

int main() {
    int n;

    while (true) {
        scanf("%d", &n);
        if (n == 0) break;

        printf("f91(%d) = %d\n", n, solve(n));
    }

    return 0;
}
