#include "monty.h"
#include <stdlib.h>

int pint_queue(stack_t *head)
{
	return (head->n);
}

int pint_stack(stack_t *head)
{
	return (head->n);
}

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	printf("%i\n", peek(stack));
}
