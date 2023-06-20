#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void push(int line_number, char *argument, stack_t **stack) {
    int value;
    stack_t *new_node;

    if (argument == NULL) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(argument);
    if (value == 0 && argument[0] != '0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "L%d: Memory allocation failed\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

