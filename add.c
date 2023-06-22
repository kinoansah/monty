#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
