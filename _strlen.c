#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: input string.
 * Return: length of s.
 */
int _strlen(char *s)
{
	/* base case */
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}
