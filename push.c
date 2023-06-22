#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **root, int data)
{
        stack_t *newNode = createNode(data);

        newNode->next = *root;
        *root = newNode;
}
