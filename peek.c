#include "monty.h"
#include <stdlib.h>

int peek_queue(stack_t *head)
{
	return (head->n);
}

int peek_stack(stack_t *head)
{
	return (head->n);
}

int peek(stack_t **stack)
{
	if (_mode(0, READ) == STACK)
		return (peek_stack(*stack));
	else
		return (peek_queue(*stack));
}
