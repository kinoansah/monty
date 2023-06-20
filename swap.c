#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void swap(int line_number, int *stack, int top) {
    int temp;
    
    if (top < 1) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}

