#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

celula* busca(celula* le, int x) {
    while (le->prox != NULL) {
        le = le->prox;
        if (le->dado == x) return le;
    }
    return NULL;
}

celula* busca_rec(celula* le, int x) {
    if (le->prox == NULL) return NULL;
    if (le->prox->dado == x) return le->prox;
    busca_rec(le->prox, x);
}