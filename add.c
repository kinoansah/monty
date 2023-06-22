#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - Adds the top two elements of the stack
 * @root: Pointer to the root of the stack
 */
void add(stack_t **root)
{
	if (isEmpty(*root) || isEmpty((*root)->next))
	{
		fprintf(stderr, "Error: can't add, stack too short.\n");
		exit(EXIT_FAILURE);
	}

	(*root)->next->n += (*root)->n;
	pop(root);
}
