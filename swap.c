#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps the top two elements of the stack
 * @root: Pointer to the root of the stack
 */
void swap(stack_t **root)
{
	int temp;

	if (isEmpty(*root) || isEmpty((*root)->next))
	{
		fprintf(stderr, "Error: can't swap, stack too short.\n");
		exit(EXIT_FAILURE);
	}

	temp = (*root)->n;
	(*root)->n = (*root)->next->n;
	(*root)->next->n = temp;
}
