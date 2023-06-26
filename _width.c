#include "main.h"

/**
 * _width - calculates the width for printing.
 * @format: formatted string in which to print the arguments.
 * @i: list of arguments to be printed.
 * @store: list of arguments.
 * Return: width.
 */
int _width(const char *format, int *i, va_list store)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width = width * 10;
			width = width + format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i = curr_i + 1;
			width = va_arg(store, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;
	return (width);
}
