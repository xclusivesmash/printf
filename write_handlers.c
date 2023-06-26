#include "main.h"

/**
 * handle_write_char - prints a string.
 * @c: char types.
 * @buffer: contains contents to be printed.
 * @flags:  calculates active flags.
 * @width: get width.
 * @precision: precision specifier.
 * @size: size specifier.
 * Return: number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	__void__(precision);
	__void__(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i] = c;
	i = i + 1;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(STDOUT, &buffer[0], 1) +
					write(STDOUT, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(STDOUT, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(STDOUT, &buffer[0], 1));
	}
	return (write(STDOUT, &buffer[0], 1));
}

/**
 * write_number - prints a string.
 * @is_negative: list of arguments.
 * @ind: char types.
 * @buffer: contains contents to be printed.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	__void__(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - write a number using a buffer.
 * @ind: index at which the number starts on the buffer.
 * @buffer: buffer.
 * @flags: flags.
 * @width: width.
 * @prec: precision specifier.
 * @length: length.
 * @padd: padding character.
 * @extra_c: extra character.
 * Return: number of chars printed.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
	{
		buffer[--ind] = '0';
		length = length + 1;
	}
	if (extra_c != 0)
		length = length + 1;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(STDOUT, &buffer[ind], length) +
					write(STDOUT, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(STDOUT, &buffer[1], i - 1) +
					write(STDOUT, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(STDOUT, &buffer[padd_start], i - padd_start) +
				write(STDOUT, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(STDOUT, &buffer[ind], length));
}

/**
 * write_unsgnd - writes an unsigned number.
 * @is_negative: number indicating whether the num is negative.
 * @ind: index at which the number starts in the buffer.
 * @buffer: array of characters.
 * @flags: flags specifiers.
 * @width: width specifier.
 * @precision: precision specifier.
 * @size: size specifier.
 * Return: number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	__void__(is_negative), __void__(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length = length + 1;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(STDOUT, &buffer[ind], length) +
					write(STDOUT, &buffer[0], i));
		}
		else
		{
			return (write(STDOUT, &buffer[0], i) +
					write(STDOUT, &buffer[ind], length));
		}
	}
	return (write(STDOUT, &buffer[ind], length));
}

/**
 * write_pointer - write a memory address.
 * @buffer: arrays of characters.
 * @ind: index at which the number starts in the buffer.
 * @length: length of number.
 * @width: width specifier.
 * @flags: flags specifier.
 * @padd: char representing the padding.
 * @extra_c: char representing extra char.
 * @padd_start: index at which padding should start.
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(STDOUT, &buffer[ind], length) +
					write(STDOUT, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(STDOUT, &buffer[3], i - 3) +
					write(STDOUT, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(STDOUT, &buffer[padd_start], i - padd_start) +
				write(STDOUT, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(STDOUT, &buffer[ind], BUFF_SIZE - ind - 1));
}
