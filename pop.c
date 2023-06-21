#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop - Removes the top element from the stack
 * @line_number: Line number where the function is called
 * @stack: Pointer to a pointer of a stack_t structures
 */
void pop(int line_number, stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
