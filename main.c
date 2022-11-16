#include "main.h"

/**
 * main - entry point of the program
 *
 * @argc: the number of arguments passed to the program
 * @argv: array of arguments passed to the program
 * @envp: array of environment variables
 * Return: EXIT_SUCCESS always
 */
int main(int __attribute__((__unused__)) argc, char *argv[], char *envp[])
{
	char **command;
	int _iMode;
	size_t buffsize = BUFFSIZE;
	int line_no = 1; /* This is just for the numbering in the error msg */

	command = malloc(sizeof(char) * BUFFSIZE);
	if (command == NULL)
		return (EXIT_FAILURE);

	_iMode = isatty(STDIN_FILENO);

	if (_iMode == 1) /* That is interactive mode */
		start_interactive_shell(command, &buffsize, argv, envp, line_no);
	else /* Start non-interactive shell */
		start_shell(command, &buffsize, argv, envp, line_no);

	return (EXIT_SUCCESS);
}

/**
 * start_interactive_shell - starts the shell in interactive mode
 *
 * @command: simply a pointer to store commands entered by users
 * @buffsize: the size of "command" in bytes
 * @argv: array of arguments passed to the program
 * @envp: array of environment variables
 * @line_no: an integer that represents the lines of command
 *           the shell has processed
 * Return: value for EXIT_SUCCESS
 */
int start_interactive_shell(char **command, size_t *buffsize,
			    char *argv[], char *envp[], int line_no)
{
	pid_t pid; /* To hold the process if of the child process */
	int status; /* Just to hold the status of the child process */

	print_string("-> "); /* This is simply the prompt */
	getline(command, buffsize, stdin);

	if (isexit(command[0]) == EXIT_SUCCESS || **command == -1 ||
	    **command == EOF)
		return (0);

	pid = fork(); /* Fork the process and store it's id */

	if (pid == -1)
		print_string("Failed to fork\n");
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
	{
		run_command(command, argv, envp, line_no);
		/* End the child process to prevent fork bomb */
		exit(98);
	}

	/* Increment line_no since we'll be getting another command from shell */
	line_no += 1;

	start_interactive_shell(command, buffsize, argv, envp, line_no);

	return (EXIT_SUCCESS);
}

/**
 * start_shell - starts shell in non-interative mode
 *
 * @command: simply a pointer to store commands entered by users
 * @buffsize: the size of "command" in bytes
 * @argv: array of arguments passed to the program
 * @envp: array of environment variables
 * @line_no: an integer that represents the lines of command
 *           the shell has processed
 * Return: value for EXIT_SUCCESS
 */
int start_shell(char **command, size_t *buffsize, char *argv[],
		char *envp[], int line_no)
{
	getline(command, buffsize, stdin);

	if (*command[0] != -1 || *command[0] != EOF)
		run_command(command, argv, envp, line_no);

	return (EXIT_SUCCESS);
}

/**
 * run_command - this functions uses the execve function to run commands
 *
 * @command: the command to be run
 * @argv: extra arguments passed to the program
 * @envp: array of environment variables the program can access.
 * @line_no: an integer that represents the lines of command
 *           the shell has processed
 */
void run_command(char **command, char *argv[],
		 char *envp[], int line_no)
{
	char *args[2];

	/* getline appends \n to the command, so strip it off */
	args[0] = _lstrip(*command);
	args[1] = 0;

	execve(args[0], args, envp);
	_perror(args[0], argv[0], line_no);
}

/**
 * _perror - standard format for shell error
 *           It prints the error to screen
 *
 * @command: the command that generated the error
 * @shell: name of the shell
 * @line_no: an integer that represents the lines of command
 *           the shell has processed
 */
void _perror(char *command, char *shell, int line_no)
{
	print_string(shell);
	print_string(": ");
	print_int(line_no);
	print_string(": ");
	perror(command);
}
