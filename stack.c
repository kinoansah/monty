#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

StackNode *createNode(int data)
{
	StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for a new node.\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return (newNode);
}

int isEmpty(StackNode *root)
{
	return (root == NULL);
}

void push(StackNode **root, int data)
{
	StackNode *newNode = createNode(data);

	newNode->next = *root;
	*root = newNode;
}

int pop(StackNode **root)
{
	StackNode *temp;
	int data;

	if (isEmpty(*root))
	{
		fprintf(stderr, "L<line_number>: can't pop an empty stack.\n");
		exit(EXIT_FAILURE);
	}

	temp = *root;
	*root = (*root)->next;
	data = temp->data;
	free(temp);
	return (data);
}

int peek(StackNode *root)
{
	if (isEmpty(root))
	{
		fprintf(stderr, "Error: can't print, stack empty.\n");
		exit(EXIT_FAILURE);
	}
	return (root->data);
}

void swap(StackNode **root)
{
	int temp;

	if (isEmpty(*root) || isEmpty((*root)->next))
	{
		fprintf(stderr, "Error: can't swap, stack too short.\n");
		exit(EXIT_FAILURE);
	}

	temp = (*root)->data;
	(*root)->data = (*root)->next->data;
	(*root)->next->data = temp;
}

void add(StackNode **root)
{
	if (isEmpty(*root) || isEmpty((*root)->next))
	{
		fprintf(stderr, "Error: can't add, stack too short.\n");
		exit(EXIT_FAILURE);
	}

	(*root)->next->data += (*root)->data;
	pop(root);
}

void printStack(StackNode *root)
{
	StackNode *current = root;

	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
