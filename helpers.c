#include "main.h"
#include <stdio.h>

/**
 * str_equals - checks if two strings are equal
 *
 * @first_string: the first string to be checked
 * @second_string: the second string to be checked
 * Return: EXIT_SUCCESS on if both strings are equal
 *         else EXIT_FAILURE
 */
int str_equals(char *first_string, char *second_string)
{
	int i;

	for (i = 0; first_string[i]; i++)
		if (first_string[i] != second_string[i])
			return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

/**
 * isexit - checks if the given string is equals to "exit"
 *
 * @str: the string to be checked
 * Return: EXIT_SUCCESS on if str equal to "exit"
 *         else EXIT_FAILURE
 */
int isexit(char *str)
{
	char *first_string = "exit";

	return (str_equals(first_string, str));
}

/**
 * _lstrip - remove the last character in a string
 *
 * @str: the string to be stripped
 * Return: EXIT_SUCCESS always
 */
char *_lstrip(char *str)
{
	size_t i = 0;
	char *str_copy = malloc(sizeof(char) * 1024);
	size_t length = _strlen(str);

	while (str[i])
	{
		if (i == (length - 1))
			break;

		str_copy[i] = str[i];
		i++;
	}

	return (str_copy);
}

/**
 * env_path - show environment variables
 *
 * @envp: array of strings containing environment variables
 * Return: EXIT_SUCCESS
 */
int env_path(char *envp[])
{
	int i;

	for (i = 0; envp[i]; i++)
	{
		print_string(envp[i]);
		_putchar('\n');
	}

	return (EXIT_SUCCESS);
}
