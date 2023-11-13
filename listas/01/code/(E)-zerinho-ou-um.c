#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

int opts[3];
char diff(int opt) {
    char init = 'A';
    for (int i = 0; i < 3; i++) {
        if (opts[i] == opt) {
            init += i;
            break;
        }
    }

    return init;
}

int main() {
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        scanf("%d", &opts[i]);
        sum += opts[i];
    }

    if (sum == 3 || sum == 0) {
        printf("empate\n");
    }
    else if (sum == 1) {
        printf("%c\n", diff(1));
    }
    else {
        printf("%c\n", diff(0));
    }

    return 0;
}