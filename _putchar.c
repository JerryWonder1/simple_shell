#include "main.h"

/**
 * _putchar - prints a character to the standard output
 *
 * @c: the character to be printed
 * Return: behaves exactly like write from unistd.h
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
