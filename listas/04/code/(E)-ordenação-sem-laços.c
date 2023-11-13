#include <stdio.h>
#include <stdlib.h>
#include "selection_sort_rec.h"

void ordena(int* v, int n) {
    selection_sort_rec(v, n, 0);
}