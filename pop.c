#include "monty.h"
#include <stdlib.h>

int pop_queue(stack_t **head)
{
	stack_t *top = *head;
	int pop_value = top->n;

	top->prev = NULL;
	*head = top->next;
	free(top);
	return (pop_value);
}

int pop_stack(stack_t **head)
{
	stack_t *top = *head;
	int pop_value = top->n;

	top->prev = NULL;
	*head = top->next;
	free(top);
	return (pop_value);
}

void pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (_mode(0, READ) == STACK)
		pop_stack(stack);
	else
		pop_queue(stack);
}
