#include "main.h"

/**
 * print_pointer - prints the value of a pointer variable.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags:  calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	__void__(width);
	__void__(size);

	if (addrs == NULL)
		return (write(STDOUT, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	__void__(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind] = map_to[num_addrs % 16];
		num_addrs = num_addrs / 16;
		length = length + 1;
		ind = ind - 1;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
	{
		extra_c = '+';
		length = length + 1;
	}
	else if (flags & F_SPACE)
	{
		extra_c = ' ';
		length = length + 1;
	}
	ind = ind + 1;
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - prints ascii codes in hexa of non printable chars.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags:  calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	__void__(flags);
	__void__(width);
	__void__(precision);
	__void__(size);

	if (str == NULL)
		return (write(STDOUT, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset = offset + append_hexa_code(str[i], buffer, i + offset);
		i = i + 1;
	}
	buffer[i + offset] = '\0';
	return (write(STDOUT, buffer, i + offset));
}

/**
 * print_reverse - prints reverse string.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags:  calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int count, i;

	count = 0;

	__void__(buffer);
	__void__(flags);
	__void__(width);
	__void__(size);

	str = va_arg(types, char *);
	if (str == NULL)
	{
		__void__(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = (i - 1); i >= 0; i--)
	{
		write(STDOUT, &str[i], 1);
		count = count + 1;
	}
	return (count);
}

/**
 * print_rot13string - print a string in rot13.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags:  calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	__void__(buffer);
	__void__(flags);
	__void__(width);
	__void__(precision);
	__void__(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(STDOUT, &x, 1);
				count = count + 1;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(STDOUT, &x, 1);
			count = count + 1;
		}
	}
	return (count);
}
