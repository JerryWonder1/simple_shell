#include "main.h"

/**
 * print_int - writes a number to stdout
 *
 * @num: the number to be printed
 * Return: the number of characters printed
 */
int print_int(long int num)
{
	int length = 0;

	if (num < 0)
	{
		_putchar('-');
		length++;
		num = -num;
	}
	if (num / 10)
	{
		print_int(num / 10);
	}

	_putchar((num % 10) + '0');
	length++;
	return (length);
}
