#ifndef FUNC
#define FUNC

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 1024

int print_string(char *str);
int _putchar(char c);
int str_equals(char *first_string, char *second_string);
int isexit(char *str);
int start_shell(char **command, size_t *buffsize, char *argv[], char *envp[]);
int print_int(long int num);
int _strlen(char *str);
char *strip_str(char *str);

#endif
