#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void swap(int line_number, stack_t **stack) {
    int temp;
    
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

