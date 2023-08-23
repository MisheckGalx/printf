#include "main.h"

/**
 * _putchar - print char c
 * @c: character ti print
 * Return: On success 1.
 * On error, -1 is returned, otherwise NULL
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
