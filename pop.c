#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Pops the top element from the stack
 * @root: Pointer to the root of the stack
 *
 * Return: Value of the popped element
 */
int pop(stack_t **root)
{
	stack_t *temp;
	int data;

	if (isEmpty(*root))
	{
		fprintf(stderr, "Error: can't pop an empty stack.\n");
		exit(EXIT_FAILURE);
	}

	temp = *root;
	*root = (*root)->next;
	data = temp->n;
	free(temp);
	return (data);
}
