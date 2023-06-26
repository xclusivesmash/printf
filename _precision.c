#include "main.h"

/**
 * _precision - calculates the precision for printing.
 * @format: formatted string in which to print the arguments.
 * @i: list of arguments to be printed.
 * @store: list of arguments.
 * Return: precision.
 */
int _precision(const char *format, int *i, va_list store)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);
	precision = 0;
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision = precision * 10;
			precision = precision + format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i = curr_i + 1;
			precision = va_arg(store, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;
	return (precision);
}
