#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int* dados;
    int N, p, u;
} fila;

int enfileira(fila* f, int x) {
    if (f->u == f->N) {
        int* aux = malloc(2 * f->N * sizeof(int));
        if (aux == NULL) return 0;

        int j = 0;
        for (int i = f->p; i < f->u; i++) {
            aux[j++] = f->dados[i];
        }
        for (int i = 0; i < f->p; i++) {
            aux[j++] = f->dados[i];
        }
        f->p = 0;
        f->u = f->N;
        f->N *= 2;

        free(f->dados);
        f->dados = aux;
    }
    f->dados[f->u++] = x;
    if (f->u == f->N) f->u = 0;
    return 1;
}