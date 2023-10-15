#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

int main() {
    int a, b, c, x, y, z;

    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);

    int ta = x / a;
    int tb = y / b;
    int tc = z / c;

    printf("%d\n", ta * tb * tc);

    return 0;
}