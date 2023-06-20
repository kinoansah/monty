#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void add(int line_number, stack_t **stack) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(line_number, stack);
}
