#ifndef FUNC
#define FUNC

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024

int print_string(char *str);
int _putchar(char c);
int str_equals(char *first_string, char *second_string);
int isexit(char *str);
int start_interactive_shell(char **command, size_t *buffsize,
			    char *argv[], char *envp[], int line_no);
int start_shell(char **command, size_t *buffsize,
			    char *argv[], char *envp[], int line_no);
void run_command(char **command, char *argv[], char *envp[], int line_no);
void _perror(char *command, char *shell, int line_no);
int print_int(long int num);
int _strlen(char *str);
char *_lstrip(char *str);
char *get_path_variable(void);
char **paths(void);
char *str_flush(char *str);
int env_path(void);

#endif
