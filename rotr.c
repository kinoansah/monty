#include "monty.h"
#include <stdlib.h>

void rotr_queue(stack_t **head, unsigned int line_number)
{
	int a;
	stack_t *h;

	if (head == NULL || *head == NULL)
		return;
	_mode(STACK, WRITE);
	h = *head;
	while (h->next)
		h = h->next;

	a = h->n;
	if (h->prev)
	{
		h->prev->next = NULL;
		free(h);
	}
	else
	{
		pop(head, line_number);
	}
	_data(a, WRITE);
	push(head, line_number);
	_mode(QUEUE, WRITE);
}

void rotr_stack(stack_t **head, unsigned int line_number)
{
	int a;
	stack_t *h;

	if (head == NULL || *head == NULL)
		return;
	h = *head;
	while (h->next)
		h = h->next;

	a = h->n;
	if (h->prev)
	{
		h->prev->next = NULL;
		free(h);
	}
	else
	{
		pop(head, line_number);
	}
	_data(a, WRITE);
	push(head, line_number);
}

void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (_mode(0, READ) == STACK)
		rotr_stack(stack, line_number);
	else
		rotr_queue(stack, line_number);
}
