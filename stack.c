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

void push(stack_t **root, int data)
{
	stack_t *newNode = createNode(data);

	newNode->next = *root;
	*root = newNode;
}

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

int peek(stack_t *root)
{
	if (isEmpty(root))
	{
		fprintf(stderr, "Error: can't print, stack empty.\n");
		exit(EXIT_FAILURE);
	}
	return (root->n);
}

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

void printStack(stack_t *root)
{
	stack_t *current = root;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
