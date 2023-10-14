#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

void imprime(celula* le) {
    while (le->prox != NULL) {
        le = le->prox;
        printf("%d -> ", le->dado);
    }
    printf("NULL\n");
}

void imprime_rec(celula* le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}