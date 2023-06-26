#include "main.h"

/**
 * _pow - computes a number raised to an exponent.
 * @x: base
 * @y: exponent
 * Return: x raised to y or -1 if y < 0.
 */
int _pow(int x, int y)
{
	/* error check */
	if (y < 0)
		return (-1);

	/* base case */
	if (y == 0)
		return (1);
	return (x * _pow(x, y - 1));
}
