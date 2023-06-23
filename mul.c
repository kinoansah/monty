#include "monty.h"

void mul(stack_t **stack, unsigned int line_number)
{
	int a, b;

	a = peek(stack);
	pop(stack, line_number);
	b = peek(stack);
	pop(stack, line_number);
	_data(b * a, WRITE);
	if (_mode(0, READ) == QUEUE)
	{
		_mode(STACK, WRITE);
		push(stack, line_number);
		_mode(QUEUE, WRITE);
	}
	else
	{
		push(stack, line_number);
	}
}
