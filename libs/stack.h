#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int data;
    struct stack* next;
} stack;

stack* make_stack() {
    stack* sk = (stack*)malloc(sizeof(stack));
    sk->next = NULL;
    return sk;
}

bool empty(stack* p) {
    return p == NULL || p->next == NULL;
}

void push(stack* p, int x) {
    stack* sk = (stack*)malloc(sizeof(stack));
    sk->data = x;
    sk->next = p->next;
    p->next = sk;
}

void pop(stack* p) {
    stack* trash = p->next;
    p->next = p->next->next;
    free(trash);
}

int top(stack* p) {
    stack* top = p->next;
    return top->data;
}