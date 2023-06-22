#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

stack_t *createNode(int n)
{
	stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for a new node.\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->next = NULL;
	return (newNode);
}

int isEmpty(stack_t *root)
{
	return (root == NULL);
}

int peek(stack_t *root)
{
	if (isEmpty(root))
	{
		fprintf(stderr, "Error: can't print, stack empty.\n");
		exit(EXIT_FAILURE);
	}
	return (root->n);
}

void printStack(stack_t *root)
{
	stack_t *current = root;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
