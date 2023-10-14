#include<stdlib.h>
#include<stdio.h>

#define MAX 112345

int main() {
    int n, m, a, k;
    scanf("%d %d %d %d", &n, &m, &a, &k);
    scanf("\n");

    char str[MAX];
    fgets(str, sizeof(str), stdin);

    for (int i = 0; i < MAX; i++) {
        if (str[i] == '\0') {
            if (m <= 0 && a <= 0 && k <= 0 && (i - 1) >= n) {
                printf("Ok =/");
            }
            else printf("Ufa :)");
            printf("\n");

            return 0;
        }
        else {
            if (str[i] >= 'a' && str[i] <= 'z') m--;
            else if (str[i] >= 'A' && str[i] <= 'Z') a--;
            else k--;
        }
    }

    return 0;
}
