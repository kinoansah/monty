#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void pop(int line_number, stack_t **stack) {
    stack_t *temp;
    
    if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
