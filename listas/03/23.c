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

void em_ordem(no* raiz) {
    stack* sk = make_stack();
    if (raiz == NULL) {
        printf("\n");
        return;
    }

    no* curr = raiz;
    while (curr != NULL) {
        push(sk, curr);
        curr = curr->esq;
    }

    while (!empty(sk)) {
        curr = top(sk);
        printf("%d ", curr->dado);
        pop(sk);

        if (curr->dir) {
            curr = curr->dir;
            while (curr != NULL) {
                push(sk, curr);
                curr = curr->esq;
            }
        }
    }
    printf("\n");
}