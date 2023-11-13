#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

int main() {
    ll l, d, k, p;
    scanf("%lld %lld", &l, &d);
    scanf("%lld %lld", &k, &p);

    printf("%lld\n", l * k + p * (l / d));

    return 0;
}