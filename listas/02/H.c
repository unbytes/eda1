#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* solve(int i, char* string) {
    if (string[i] == '\0') return string;

    if (string[i] == 'x') string[i] = 'y';
    return solve(i + 1, string);
}

int main() {
    char* string = malloc(81);
    scanf("%s", string);
    printf("%s\n", solve(0, string));
    return 0;
}