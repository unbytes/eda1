#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 112

static int compfn(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void sort(const char* arr[], int n) {
    qsort(arr, n, sizeof(const char*), compfn);
}

int main() {
    int n, test = 1;
    while (scanf("%d", &n) != EOF) {
        scanf("\n");

        const char* arr[n];
        int numbers[MAX], mx = 11;
        char tmp[n][MAX], nws[n][MAX];
        for (int i = 0; i < n; i++) {
            fgets(tmp[i], sizeof(tmp[i]), stdin);

            int j = 0;
            for (; tmp[i][j] != ' '; j++) {}
            j++;

            int k = 0;
            for (; tmp[i][j] != '\n'; j++) nws[i][k++] = tmp[i][j];
            nws[i][k] = '\0';
            numbers[i] = atoi(nws[i]);
            if (numbers[i] < mx) mx = numbers[i];

            if (numbers[i] == 10) {
                nws[i][0] = ':';
                nws[i][1] = '\0';
                k = 1;
            }

            nws[i][k++] = ' ';
            for (int j = 0; tmp[i][j] != ' '; j++) nws[i][k++] = tmp[i][j];
            nws[i][k++] = '\0';

            arr[i] = nws[i];
        }
        sort(arr, n);

        int counter = 0, init = 0;
        for (int i = 0; i < n; i++) if (numbers[i] == mx) counter++;
        for (; arr[counter - 1][init] != ' '; init++) {}
        init++;

        printf("Instancia %d\n", test++);
        printf("%s\n\n", &arr[counter - 1][init]);
    }

    return 0;
}
