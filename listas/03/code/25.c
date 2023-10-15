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

void pre_ordem(no* raiz) {
    if (raiz == NULL) {
        printf("\n");
        return;
    }

    stack* sk = make_stack();
    push(sk, raiz);

    while (!empty(sk)) {
        no* node = top(sk);
        pop(sk);

        printf("%d ", node->dado);

        if (node->dir) push(sk, node->dir);
        if (node->esq) push(sk, node->esq);

    }
    printf("\n");
}