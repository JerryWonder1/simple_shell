#include "main.h"

int main(int __attribute__((__unused__)) argc, char *argv[], char *envp[])
{
	char **command;
	size_t buffsize = BUFFSIZE;

	command = malloc(sizeof(char) * BUFFSIZE);
	start_shell(command, &buffsize, argv, envp);

	return (0);
}

/**
 * start_shell - starts the shell
 *
 * Return: value for EXIT_SUCCESS
 */
int start_shell(char **command, size_t *buffsize,
		char __attribute__((__unused__)) *argv[], char *envp[])
{
	char *args[2];

	print_string("-> ");
	getline(command, buffsize, stdin);

	if (isexit(command[0]) == EXIT_SUCCESS || **command == -1 ||
	    **command == EOF)
		return (0);

	_strlen(*command);

	args[0] = strip_str(*command);
	args[1] = 0;

	_strlen(args[0]);
	if (execve(args[0], args, envp) == -1)
			perror("Error");

	print_string(args[0]);

	start_shell(command, buffsize, argv, envp);

	return (EXIT_SUCCESS);
}
