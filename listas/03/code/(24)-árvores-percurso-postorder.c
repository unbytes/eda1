#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no* esq, * dir;
} no;

typedef struct stack {
    no* dado;
    struct stack* prox;
} stack;

stack* make_stack() {
    stack* sk = (stack*)malloc(sizeof(stack));
    sk->prox = NULL;
    return sk;
}

bool empty(stack* p) {
    return p == NULL || p->prox == NULL;
}

void push(stack* p, no* x) {
    stack* sk = (stack*)malloc(sizeof(stack));
    sk->dado = x;
    sk->prox = p->prox;
    p->prox = sk;
}

void pop(stack* p) {
    stack* trash = p->prox;
    p->prox = p->prox->prox;
    free(trash);
}

no* top(stack* p) {
    stack* top = p->prox;
    return top->dado;
}

void pos_ordem(no* raiz) {
    if (raiz == NULL) {
        printf("\n");
        return;
    }

    stack* s1 = make_stack(), * s2 = make_stack();
    push(s1, raiz);
    no* node;

    while (!empty(s1)) {
        node = top(s1);
        pop(s1);
        push(s2, node);

        if (node->esq) push(s1, node->esq);
        if (node->dir) push(s1, node->dir);
    }

    while (!empty(s2)) {
        printf("%d ", top(s2)->dado);
        pop(s2);
    }
    printf("\n");
}