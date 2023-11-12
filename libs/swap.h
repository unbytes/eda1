#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}