#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

int main() {
    float a, g, ra, rg;

    scanf("%f %f %f %f", &a, &g, &ra, &rg);
    float ta = 1.0 / ra;
    float tg = 1.0 / rg;

    float x = ta * a, y = tg * g;

    if (x < y) {
        printf("A\n");
    }
    else {
        printf("G\n");
    }

    return 0;
}