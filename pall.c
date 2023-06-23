#include "monty.h"

void pall_queue(stack_t *head)
{
	if (head == NULL)
		return;

	printf("%i\n", head->n);
	pall_queue(head->next);
}

void pall_stack(stack_t *head)
{
	if (head == NULL)
		return;

	printf("%i\n", head->n);
	pall_stack(head->next);
}

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (stack == NULL)
		return;
	if (_mode(0, READ) == STACK)
		pall_stack(*stack);
	else
		pall_queue(*stack);
}
