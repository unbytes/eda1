#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

int t = 1;
void solve(int n) {
    int m, tot = 0;
    char ch;

    scanf("%d", &tot);
    for (int i = 0; i < n - 1; i++) {
        scanf("%c", &ch);
        scanf("%d", &m);

        if (ch == '+') tot += m;
        else tot -= m;
    }

    printf("Teste %d\n", t++);
    printf("%d\n\n", tot);
}

int main() {
    //int t = 1;
    //scanf("%d", &t);

    while (true) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;

        solve(n);
    }

    return 0;
}