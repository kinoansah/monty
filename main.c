#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/* Example usage */
	stack_t *stack = NULL;

	push(1, "10", &stack);
	push(2, "20", &stack);
	pall(&stack);
	pint(&stack, 3);
	pop(4, &stack);
	swap(5, &stack);
	add(6, &stack);
	pall(&stack);
	nop();

	return (0);
}

