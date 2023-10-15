#include <stdio.h>
#include <stdlib.h>

int solve(int i, int ans, char* string) {
    if (string[i] == '\0') return ans;

    if (string[i - 2] == string[i]) ans++;
    return solve(i + 1, ans, string);
}

int main() {
    char* string = malloc(201);
    scanf("%s", string);
    printf("%d\n", solve(2, 0, string));
}