#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void add(int line_number, int *stack, int *top) {
    if (*top < 1) {
        printf("L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack[*top - 1] += stack[*top];
    (*top)--;
}

