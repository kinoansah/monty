#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void push(int line_number, char *argument, int *stack, int *top) {
    int value;
    
    if (argument == NULL) {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(argument);
    if (value == 0 && argument[0] != '0') {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (*top == 100 - 1) {
        printf("L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack[++(*top)] = value;
}

