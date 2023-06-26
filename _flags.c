#include "main.h"

/**
 * _flags - calculates active flags.
 * @format: formatted string in which to print the arguments.
 * @i: take a parameter.
 * Return: flags.
 */
int _flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	curr_i = *i + 1;
	while (format[curr_i] != '\0')
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags = flags | FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
		curr_i = curr_i + 1;
	}
	*i = curr_i - 1;
	return (flags);
}
