#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	int a, b;

	a = peek(stack);
	pop(stack, line_number);
	b = peek(stack);
	pop(stack, line_number);
	_data(a, WRITE);
	push(stack, line_number);
	_data(b, WRITE);
	push(stack, line_number);
}
