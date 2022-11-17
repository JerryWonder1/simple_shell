#include "main.h"

/**
 * get_path_variable - gets the value of the path variable from the environment
 *                     variables excluding 'PATH=' from the string
 *
 * Return: the value of the path environment variable
 */
char *get_path_variable(void)
{
	char *path, *path_copy;
	int i, j;
	char *sub_str = "PATH=";
	extern char **environ;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; sub_str[j]; j++)
		{
			if (sub_str[j] != *environ[j])
				break;
			if (j == 4)
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
 * Return: an array of directories in path
 */
char **paths(void)
{
	int i, j, k, n;
	char *path = get_path_variable();

	char tmp[200], **path_array;

	k = 0;
	n = 0;

	path_array = malloc(sizeof(char) * 4096);
	if (path_array == NULL)
		return (NULL);

	for (i = 0; path[i]; i++)
	{
		str_flush(tmp); /* to clear previous values  */
		for (j = i; path[j]; j++)
		{
			if (path[j] == ':')
				break;
			tmp[k++] = path[j];
		}

		path_array[n++] = tmp;
		i = ++j; /* this will help skip the : character */
	}

	free(path);

	return (path_array);
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
