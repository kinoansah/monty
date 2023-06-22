#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * createNode - Creates a new node with the given value
 * @n: The value to assign to the new node
 *
 * Return: A pointer to the newly created node
 */
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

/**
 * isEmpty - Checks if the stack is empty
 * @root: The root of the stack
 *
 * Return: 1 if the stack is empty, 0 otherwise
 */
int isEmpty(stack_t *root)
{
	return (root == NULL);
}

/**
 * peek - Returns the value at the top of the stack without removing it
 * @root: The root of the stack
 *
 * Return: The value at the top of the stack
 */
int peek(stack_t *root)
{
	if (isEmpty(root))
	{
		fprintf(stderr, "Error: can't print, stack empty.\n");
		exit(EXIT_FAILURE);
	}
	return (root->n);
}

/**
 * printStack - Prints all elements in the stack
 * @root: The root of the stack
 */
void printStack(stack_t *root)
{
	stack_t *current = root;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
