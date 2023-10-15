#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void solve(int t) {
    int* cars = malloc(t * sizeof(int)), init = 1, y;
    for (int i = 0; i < t; i++) scanf(" %d", &cars[i]);

    stack* sk = make_stack();
    for (int i = 0; i < t; i++) {
        if (cars[i] == init) init++;
        else {
            while (!empty(sk) && top(sk) == init) {
                pop(sk);
                init++;
            }

            if (!empty(sk) && top(sk) < cars[i]) {
                printf("no\n");
                return;
            }
            push(sk, cars[i]);
        }
    }
    printf("yes\n");
}

int main() {
    int t;

    while (true) {
        scanf("%d", &t);
        if (t == 0) break;

        solve(t);
    }

    return 0;
}