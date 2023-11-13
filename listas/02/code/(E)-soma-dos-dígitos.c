#include <stdio.h>
#include <stdlib.h>

int ans = 0;
void accumulate(char* number, int i) {
    if (number[i] == '\0') return;
    ans += number[i] - '0';
    return accumulate(number, i + 1);
}

int main() {
    char* number = malloc(101);
    scanf("%s", number);

    accumulate(number, 0);
    printf("%d\n", ans);
    return 0;
}