#include "main.h"


/**
 * append_hexa_code - append ascci in hexadecimal code to buffer.
 * @buffer: array of chars.
 * @i: index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code = ascii_code * -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_digit - verifies if a char is a digit.
 * @c: char to be evaluated.
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_number - casts a number to the specified size.
 * @num: number to be casted.
 * @size: number indicating the type to be casted.
 * Return: casted value of num.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_SHORT)
		return ((short)num);
	else if (size == S_LONG)
		return (num);
	return ((int)num);
}

/**
 * convert_size_unsgnd - casts a number to the specified size.
 * @num: number to be casted.
 * @size: number indicating the type to be casted
 * Return: casted value of num.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_SHORT)
		return ((unsigned short)num);
	else if (size == S_LONG)
		return (num);
	/* cast return value */
	return ((unsigned int)num);
}

/**
 * is_printable - evaluates if a char is printable.
 * @c: char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
