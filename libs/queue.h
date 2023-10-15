#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int data;
    struct queue* next;
} queue;

queue* make_queue() {
    queue* qs = (queue*)malloc(sizeof(queue));
    qs->next = NULL;
    return qs;
}

bool empty(queue* f) {
    return f == NULL || f->next == NULL;
}

queue* push(queue* f, int x) {
    queue* node = (queue*)make_queue();
    node->next = f->next;
    f->next = node;
    f->data = x;
    return node;
}

void pop(queue* f) {
    f->next = f->next->next;
}

queue* front(queue* f) {
    return f->next;
}