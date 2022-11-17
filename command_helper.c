#include "main.h"

/**
 * command_exists - searches for PATH dir containing command
 *
 * @command: the command to be searched for
 *
 * Return: unsigned int character count
 */

char *command_exists(char *command)
{
	int i = 0;
	char *ret;
	char **path_array;

	if (command[0] == '/')
	{
		if (access(command, F_OK | X_OK) == 0)
		{
			return (command);
		}
	}
	else
	{
		path_array = paths();

		while (path_array[i])
		{
			ret = append_path(path_array[i], command);
			if (access(ret, F_OK | X_OK) == 0)
				break;
			free(ret);
			i++;
		}

		/*free_tokens(path_array);*/

		return (ret);
	}

	return (NULL);
}


/**
 * append_path - concatenates a path token with a command token
 *
 * @path: path string to append to
 * @command: command string to append
 * Return: buffer to appended path
 */

char *append_path(char *path, char *command)
{
	char *buffer;
	size_t a = 0, b = 0;

	if (command == 0)
		command = "";
	if (path == 0)
		path = "";
	buffer = malloc(sizeof(char) * _strlen(path) + _strlen(command) + 2);
	if (buffer == NULL)
		return (NULL);
	while (path[a])
	{
		buffer[a] = path[a];
		a++;
	}
	if (path[a - 1] != '/')
	{
		buffer[a] = '/';
		a++;
	}
	while (command[b])
	{
		buffer[a + b] = command[b];
		b++;
	}
	buffer[a + b] = '\0';

	return (buffer);
}
