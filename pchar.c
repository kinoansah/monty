#include "monty.h"
#include <stdlib.h>

int pchar_queue(stack_t *head)
{
	return (head->n);
}

int pchar_stack(stack_t *head)
{
	return (head->n);
}

void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	printf("%c\n", peek(stack));
}
