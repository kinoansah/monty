#include "monty.h"
#include <string.h>

int isnumber(char *str)
{
	int isnumber = 0;

	if (str && (*str == '+' || *str == '-'))
	{
		isnumber = strlen(str) == 1;
		str++;
	}

	while (*str && isnumber == 0)
	{
		isnumber = *str < '0' || *str > '9';
		str++;
	}

	return (isnumber);
}
