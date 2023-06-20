#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @line_number: Line number where the function is called
 * @argument: Argument to be pushed onto the stack (as a string)
 * @stack: Pointer to a pointer of a stack_t structure
 */
void push(int line_number, char *argument, stack_t **stack)
{
	int value;
	stack_t *new_node;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);

	if (value == 0 && argument[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	/* Add the new node to the top of the stack */
	if (*stack != NULL)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
}
