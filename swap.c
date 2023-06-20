#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @line_number: Line number where the function is called
 * @stack: Pointer to a pointer of a stack_t structure
 */
void swap(int line_number, stack_t **stack)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	return;
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

