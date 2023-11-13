#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

int desenfileira(celula* f, int* y) {
    if (f == NULL || f->prox == NULL) return 0;

    celula* trash = f->prox;

    *y = f->prox->dado;
    f->prox = f->prox->prox;

    free(trash);
    return 1;
}