#include "main.h"

/**
 * print_char - prints a character.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c;

	c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - prints a given string.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	__void__(buffer), __void__(flags), __void__(width);
	__void__(precision), __void__(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length = length + 1;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(STDOUT, &str[0], length);
			i = (width - length);
			while (i > 0)
			{
				write(STDOUT, " ", _strlen(" "));
				i = i - 1;
			}
			return (width);
		}
		else
		{
			for (i = (width - length); i > 0; i--)
				write(STDOUT, " ", _strlen(" "));
			write(STDOUT, &str[0], length);
			return (width);
		}
	}
	return (write(STDOUT, str, length));
}

/**
 * print_percent - prints a percent sign.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	__void__(types), __void__(buffer), __void__(flags);
	__void__(width);
	__void__(precision);
	__void__(size);
	return (write(STDOUT, "%%", 1));
}

/**
 * print_int - prints an integer.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = (BUFF_SIZE - 2);
	long int n = va_arg(types, long int);
	unsigned long int num;
	int is_negative = 0;

	n = convert_size_number(n, size);

	if (n == 0)
	{
		buffer[i] = '0';
		i = i - 1;
	}
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		i = i - 1;
		num = num / 10;
	}
	i = i + 1;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - prints an unsigned number.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, summation;
	int store;
	unsigned int array[32];

	__void__(buffer);
	__void__(flags);
	__void__(width);
	__void__(precision);
	__void__(size);

	n = va_arg(types, unsigned int);
	m = _pow(2, 31);
	array[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m = m / 2;
		array[i] = (n / m) % 2;
	}
	for (i = 0, summation = 0, store = 0; i < 32; i++)
	{
		summation = summation + array[i];
		if (summation || i == 31)
		{
			char z = '0' + array[i];

			write(STDOUT, &z, 1);
			store = store + 1;
		}
	}
	return (store);
}
