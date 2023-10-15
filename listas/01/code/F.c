#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

int main() {
    int last, curr, dir;

    scanf("%d", &last);
    scanf(" %d", &curr);

    if (curr > last) dir = 1;
    else dir = 3;

    for (int i = 0; i < 3; i++) {
        scanf(" %d", &curr);
        if ((curr > last && dir == 3) || (curr < last && dir == 1)) {
            printf("N\n");
            return 0;
        }
        last = curr;
    }

    if (dir == 1) printf("C\n");
    else printf("D\n");

    return 0;
}