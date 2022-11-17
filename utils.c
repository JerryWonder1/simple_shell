#include "main.h"

/**
 * get_path_variable - gets the value of the path variable from the environment
 *                     variables excluding 'PATH=' from the string
 *
 * @environ: array of strings of environment variables
 * Return: the value of the path environment variable
 */
char *get_path_variable(char *environ[])
{
	char *path, *path_copy;
	int i, j;
	char *sub_str = "PATH=";

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; sub_str[j]; j++)
		{
			if (sub_str[j] != environ[i][j])
				break;
			if (j == (_strlen(sub_str) - 1))
			{
				path = environ[i];
				break;
			}
		}
	}

	/* to remove 'PATH=' from the string  */

	j = 0;
	path_copy = malloc(sizeof(char) * (_strlen(path) - 5));
	for (i = 5; path[i]; i++)
		path_copy[j++] = path[i];

	return (path_copy);

}

/**
 * paths - returns an array of directories in PATH
 *
 * @environ: array of strings of environment variables
 * Return: an array of directories in path
 */
char **paths(char *environ[])
{
	char *path = get_path_variable(environ);
	char **path_array = tokenize(path, ":");

	free(path);

	return (path_array);
}

/**
 * tokenize - converts a string to an array of strings based on delimiters
 *
 * @str: the string to be converted
 * @delimiters: a string that contains characters used as delimiters
 * Return: an array of strings
 */
char **tokenize(char *str, char *delimiters)
{
	int i, j, k, n;

	char tmp[200], **tokens;

	k = 0;
	n = 0;

	tokens = malloc(sizeof(char) * 4096);
	if (tokens == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		str_flush(tmp); /* to clear previous values  */
		for (j = i; str[j]; j++)
		{
			if (in_string(delimiters, &str[j]) == EXIT_SUCCESS)
				break;
			tmp[k++] = str[j];
		}

		k = 0;
		tokens[n++] = str_copy(tmp);
		i = j; /* this will help skip the : character */
	}

	return (tokens);
}

/**
 * str_flush - sets all the characters in a string to '\0'
 *
 * @str: the string to be flushed
 * Return: the flushed string
 */
char *str_flush(char *str)
{
	while (*str)
	{
		*str = '\0';
		str++;
	}

	return (str);
}

/**
 * free_tokens - frees the buffer used to store a token
 *
 * @buffer: buffer used to store the token
 */
void free_tokens(char **buffer)
{
	int i = 0;

	while (buffer[i])
		free(buffer[i++]);

	free(buffer);
}
