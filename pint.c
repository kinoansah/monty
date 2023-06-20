#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void pint(int line_number, stack_t **stack) {
    if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
