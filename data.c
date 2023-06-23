#include "monty.h"

int _mode(int data, int mode)
{
	static int MODE;

	if (mode)
		MODE = data;

	return (MODE);
}

int _data(int data, int mode)
{
	static int DATA;

	if (mode)
		DATA = data;

	return (DATA);
}

int _error(int data, int mode)
{
	static int ERROR;

	if (mode)
		ERROR = data;

	return (ERROR);
}
