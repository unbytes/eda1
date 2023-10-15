#include<stdlib.h>
#include<stdio.h>

#define MAX 112345

int main() {
    char string[MAX];

    fgets(string, sizeof(string), stdin);

    for (int i = 0; i < MAX; i++) {
        if (string[i] == '\0') {
            for (int j = i - 2; j >= 0; j--) {
                printf("%c", string[j]);
            }
            printf("\n");
            return 0;
        }
    }

    return 0;
}
