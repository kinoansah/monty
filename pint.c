#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void pint(int line_number, int *stack, int top) {
    if (top == -1) {
        printf("L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack[top]);
}
