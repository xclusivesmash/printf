#include "main.h"

/**
 * _printf - printf function.
 * @format: format.
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list store;
	char buffer[BUFF_SIZE];

	/* ERROR HANDLING */
	if (format == NULL)
		return (-1);

	va_start(store, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			print_buffer(buffer, &buff_ind);
			flags = _flags(format, &i);
			width = _width(format, &i, store);
			precision = _precision(format, &i, store);
			size = _size(format, &i);
			++i;
			printed = handle_print(format, &i, store, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars = printed_chars + printed;
		}
		else
		{
			buffer[buff_ind] = format[i];
			buff_ind = buff_ind + 1;
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars = printed_chars + 1;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(store);
	return (printed_chars);
}
