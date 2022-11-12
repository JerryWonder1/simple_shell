#include "main.h"

/**
 * print_string - prints a string to standard output
 *
 * @str: the string to be printed
 * Return: number of characters printed
 */
int print_string(char *str)
{
	int i = 0;

	while (str[i])
		_putchar(str[i++]);

	return (i);
}

/**
 * _strlen - gets the length of the string
 *
 * @str: the string to be checked
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	print_int(i);
	return (i);
}
