#include <stdio.h>
#include <stdlib.h>

typedef struct pair {
    char* first;
    int second;
} pair;


pair itoa(int n) {
    char* number = malloc(1123);
    char* revers = malloc(1123);

    int i = 0, j = 0;
    while (n) {
        number[i++] = '0' + (n % 10);
        n /= 10;

    }
    number[i] = '\0';

    revers[i] = '\0';
    while (i) {
        revers[j++] = number[--i];
    }

    pair ans;
    ans.first = revers;
    ans.second = j;
    return ans;
}

int main() {
    while (1) {
        char* number = malloc(1123), * initial = malloc(1123);
        scanf("%s", number);
        initial = number;

        if (number[0] == '0') break;

        int length = 1123, degree = 0;
        while (length > 1) {
            int x = 0, fn = 0;
            while (number[x] != '\0') {
                fn += number[x++] - '0';
            }

            pair info = itoa(fn);
            number = info.first;
            length = info.second;
            degree++;
        }

        if ((number[0] - '0') % 9 == 0) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", initial, degree);
        }
        else {
            printf("%s is not a multiple of 9.\n", initial);
        }
    }

    return 0;
}