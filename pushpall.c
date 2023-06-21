#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int is_integer(const char *str)
{
    int i = 0;

    if (str == NULL || *str == '\0')
        return 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}

void push(int line_number, char *argument, stack_t **stack)
{
    int value;
    stack_t *new_node;

    if (argument == NULL || !is_integer(argument))
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

void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

