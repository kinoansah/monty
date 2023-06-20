#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @line_number: Line number where the function is called
 * @stack: Pointer to a pointer of a stack_t structure
 */
void add(int line_number, stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(line_number, stack);
}
