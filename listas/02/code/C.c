#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pair {
    int first, second;
} pair;

char string[101];
pair copy_without_x(int i, int j, char* tmp) {
    if (string[i] == '\n' || string[i] == '\0') {
        tmp[j] = '\0';
        pair pr;
        pr.first = i;
        pr.second = j;
        return pr;
    }

    if (string[i] == 'x') return copy_without_x(i + 1, j, tmp);
    else {
        tmp[j] = string[i];
        return copy_without_x(i + 1, j + 1, tmp);
    }
}

void complete_with_x(int i, int n, char* tmp) {
    if (n == i) {
        tmp[i] = '\0';
        return;
    }

    tmp[i] = 'x';
    return complete_with_x(i + 1, n, tmp);
}

int main() {
    fgets(string, sizeof(string), stdin);

    char* tmp = malloc(101 * sizeof(char));
    pair end = copy_without_x(0, 0, tmp);
    complete_with_x(end.second, end.first, tmp);

    printf("%s\n", tmp);
}