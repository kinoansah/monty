#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int pstr_queue(stack_t *head)
{
	if (head == NULL || (head->n <= 0 || head->n > 127))
		return (0);

	return (printf("%c", head->n) + pstr_queue(head->next));
}

int pstr_stack(stack_t *head)
{
	if (head == NULL || (head->n <= 0 || head->n > 127))
		return (0);
	return (printf("%c", head->n) + pstr_stack(head->next));
}

void pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (_mode(0, READ) == STACK)
		pstr_stack(*stack);
	else
		pstr_queue(*stack);
	printf("\n");
}
