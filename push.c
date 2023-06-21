#include <stdlib.h>
#include "monty.h"
#include <stdio.h>

int is_valid_integer(const char *str)
{
    if (*str == '\0') /* Empty string */
        return 0;

    if (*str == '-' || *str == '+') /* Skip sign if present */
        str++;

    if (*str == '\0') /* Only sign present */
        return 0;

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9') /* Non-digit character found */
            return 0;
        str++;
    }

    return 1;
}

void push(int line_number, char *argument, stack_t **stack)
{
    int value;
    stack_t *new_node;

    if (argument == NULL || !is_valid_integer(argument))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(argument);
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

