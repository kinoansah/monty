#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void push(int line_number, char *argument, int *stack, int *top) {
    int value;

    if (argument == NULL) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(argument);
    if (value == 0 && argument[0] != '0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (*top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack[++(*top)] = value;
}

