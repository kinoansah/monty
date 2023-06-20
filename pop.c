#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void pop(int line_number, int *top) {
    if (*top == -1) {
        printf("L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*top)--;
}
