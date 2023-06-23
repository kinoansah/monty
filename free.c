#include <stdlib.h>
#include "monty.h"

void _free(stack_t *head)
{
	stack_t *tmp, *p = head;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

