#include<stdlib.h>
#include<stdio.h>

#define MAX 1123

int main() {
    char letter;
    scanf("%c", &letter);
    scanf("\n");

    char str[MAX];
    fgets(str, sizeof(str), stdin);

    int words = 1, count = 0, ans = 0;
    for (int i = 0; i < MAX && str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            words++;
            if (count > 0) ans++;
            count = 0;
        }
        else if (str[i] == letter) count++;
    }
    if (count > 0) ans++;

    printf("%.1f\n", ((float)ans / (float)words) * 100);

    return 0;
}
