#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

char string[100007];
void solve() {
    scanf("%s", string);

    stack* sk = make_stack();
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        if (string[i] == '[' || string[i] == '{' || string[i] == '(') push(sk, string[i]);
        else {
            char y;
            if (!empty(sk)) {
                int y = top(sk);
                pop(sk);

                if (y == string[i] - 1 || y == string[i] - 2) continue;
            }
            else {
                printf("N\n");
                return;
            }
        }
    }

    if (!empty(sk)) printf("N\n");
    else printf("S\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}