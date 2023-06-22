#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes a new element onto the stack
 * @root: Pointer to the root of the stack
 * @data: Data value of the new element
 */
void push(stack_t **root, int data)
{
	stack_t *newNode = createNode(data);

	newNode->next = *root;
	*root = newNode;
}
