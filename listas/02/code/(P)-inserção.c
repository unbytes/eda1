#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

void insere_inicio(celula* le, int x) {
    celula* new = malloc(sizeof(celula));
    new->dado = x;
    new->prox = le->prox;
    le->prox = new;
}

void insere_antes(celula* le, int x, int y) {
    celula* new = malloc(sizeof(celula)), * last;
    new->dado = x;

    while (le->prox != NULL) {
        last = le;
        le = le->prox;
        if (le->dado == y) {
            new->prox = le;
            last->prox = new;
            return;
        }
    }

    le->prox = new;
    new->prox = NULL;
}