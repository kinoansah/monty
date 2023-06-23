#include "monty.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buffer[256], *token, *tokens[2];
	stack_t *stack = NULL;
	unsigned int line_number = 1, i = 0;
	FILE *script;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	script = fopen(argv[1], "r");
	if (script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), script))
	{
		i = 0;
		tokens[0] = tokens[1] = NULL;
		buffer[strcspn(buffer, "\n#")] = 0;
		token = strtok(buffer, " \t");
		while (token && !isspace(*token) && i < 2)
		{
			tokens[i++] = token;
			token = strtok(NULL, " \t");
		}
		if ((!i || *tokens[0] == '#') && line_number++)
			continue;
		if (exec(&stack, tokens, line_number++) == EXIT_FAILURE)
		{
			fclose(script);
			_free(stack);
			return (EXIT_FAILURE);
		}
	}
	fclose(script);
	_free(stack);
	return (EXIT_SUCCESS);
}
