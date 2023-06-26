#include "main.h"

/**
 * print_unsigned - prints an unsigned number.
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i;
	unsigned long int num;

	num = va_arg(types, unsigned long int);
	num = convert_size_unsgnd(num, size);
	i = BUFF_SIZE - 2;

	if (num == 0)
	{
		buffer[i] = '0';
		i = i - 1;
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		i = i - 1;
		num = num / 10;
	}
	i = i + 1;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation (base 8)
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i;
	unsigned long int num;
	unsigned long int init_num;

	i = BUFF_SIZE - 2;
	num = va_arg(types, unsigned long int);
	init_num = num;
	__void__(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i] = '0';
		i = i - 1;
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i] = (num % 8) + '0';
		i = i - 1;
		num = num / 8;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i] = '0';
		i = i - 1;
	}
	i = i + 1;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * (base 10).
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal notation.
 * (base 10).
 * @types: list of arguments.
 * @buffer: contains contents to print.
 * @flags: calculates active flags.
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of characters printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - prints a hexadecimal number in lower or upper.
 * @types: list of arguments.
 * @map_to: array of values to map the number to.
 * @buffer: contains contents to print.
 * @flags:  calculates active flags.
 * @flag_ch: calculates active flags
 * @width: specified width.
 * @precision: precision specification.
 * @size: size specifier.
 * @size: size specification.
 * Return: number of characters printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i;
	unsigned long int num;
	unsigned long int init_num;

	i = BUFF_SIZE - 2;
	num = va_arg(types, unsigned long int);
	init_num = num;
	__void__(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
	{
		buffer[i] = '0';
		i = i - 1;
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i] = map_to[num % 16];
		i = i - 1;
		num = num / 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i = i + 1;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
