#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int* dados;
    int N, p, u;
} fila;

int redimenciona(fila* f) {
    f->dados = realloc(f->dados, 2 * f->N * sizeof(int));
    if (f->dados == NULL) return 0;

    int j = f->p, np = f->p;
    
    int rest = f->N % 2;
    if (f->p > (f->N / 2) + rest) {
        j += f->N;
        np += f->N;
    }

    for (int i = f->p; i != f->u; i = (i + 1) % f->N) {
        f->dados[j] = f->dados[i];
        j = (j + 1) % (2 * f->N);
    }

    f->p = np;
    f->u = j;
    f->N *= 2;

    return 1;
}

int enfileira(fila* f, int x) {
    if ((f->u + 1) % f->N == f->p && !redimenciona(f)) return 0;

    f->dados[f->u++] = x;
    if (f->u == f->N) f->u = 0;
    return 1;
}