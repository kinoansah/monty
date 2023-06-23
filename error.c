#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

int push_error(char **tokens, unsigned int line_number)
{
	if (tokens[1] == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}

	if (isnumber(tokens[1]) == 1)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}

	_data(atoi(tokens[1]), WRITE);

	return (EXIT_SUCCESS);
}

int pop_error(stack_t **stack, unsigned int line_number)
{
	if (stack_t_len(stack) == 0)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

int read_error(char **tokens, stack_t **stack, unsigned int line_number)
{
	int i;
	char *long_error = "L%i: can't %s, value out of range\n";

	if (stack_t_len(stack) == 0)
	{
		fprintf(stderr, "L%i: can't %s, stack empty\n", line_number, tokens[0]);
		return (EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "pchar") == 0)
	{
		i = peek(stack);
		if (i < 0 || i > 127)
		{
			fprintf(stderr, long_error, line_number, tokens[0]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int math_error(char **tokens, stack_t **stack, unsigned int line_number)
{
	int a;
	char *_zero[7] = {"div", "mod", NULL};

	if (stack_t_len(stack) < 2)
	{
		fprintf(stderr, "L%i: can't %s, stack too short\n", line_number, tokens[0]);
		return (EXIT_FAILURE);
	}

	if (find(_zero, tokens[0]) != -1)
	{
		a = peek(stack);
		if (a == 0)
		{
			fprintf(stderr, "L%i: division by zero\n", line_number);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int error(char **tokens, stack_t **stack, unsigned int line_number)
{
	char *_push[2] = {"push", NULL};
	char *_read[3] = {"pchar", "pint", NULL};
	char *_pop[2] = {"pop", NULL};
	char *_math[7] = {"div", "add", "sub", "mul", "mod", "swap", NULL};


	if (find(_push, tokens[0]) != -1)
	{
		return (push_error(tokens, line_number));
	}
	else if (find(_read, tokens[0]) != -1)
	{
		return (read_error(tokens, stack, line_number));
	}
	else if ((find(_pop, tokens[0]) != -1))
	{
		return (pop_error(stack, line_number));
	}
	else if ((find(_math, tokens[0]) != -1))
	{
		return (math_error(tokens, stack, line_number));
	}

	return (EXIT_SUCCESS);
}
