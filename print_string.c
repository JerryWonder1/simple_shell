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

	return (i);
}

/**
 * str_copy - copies a string to a new buffer and returns the new buffer
 *
 * @str: the string to be copied
 * Return: a buffer containing copied string
 */
char *str_copy(char *str)
{
	int i = 0;
	char *buffer = malloc(_strlen(str) * sizeof(char));

	if (buffer == NULL)
		return (NULL);

	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}

	return (buffer);
}

/**
 * in_string - checks if a character exists in a string
 *
 * @haystack: the main string
 * @needle: the character to be checkedd for
 * Return: EXIT_SUCCESS on success
 *         else EXIT_FAILURE
 */
int in_string(char *haystack, char *needle)
{
	int i = 0;

	while (haystack[i])
	{
		if (haystack[i] == *needle)
			return (EXIT_SUCCESS);
		i++;
	}

	return (EXIT_FAILURE);
}
