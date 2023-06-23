#include "monty.h"

unsigned int stack_t_len(stack_t **stack)
{
	unsigned int len = 0;
	stack_t *start = NULL;

	if (stack == NULL)
		return (len);

	for (start = *stack; start; start = start->next)
		len++;

	return (len);
}

