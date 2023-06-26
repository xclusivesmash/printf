#include "main.h"

/**
 * _size - calculates the size to cast the argument.
 * @format: formatted string in which to print the arguments.
 * @i: list of arguments to be printed.
 * Return: precision.
 */
int _size(const char *format, int *i)
{
	int curr_i;
	int size = 0;

	curr_i = *i + 1;
	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size != 0)
		*i = curr_i;
	else
		*i = curr_i - 1;
	return (size);
}
