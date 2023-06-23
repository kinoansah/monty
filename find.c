#include "monty.h"
#include <string.h>

int find(char **list, char *query)
{
	unsigned int i = 0;

	for (i = 0; list && list[i]; i++)
	{
		if (strcmp(query, list[i]) == 0)
			return (i);
	}

	return (-1);
}
