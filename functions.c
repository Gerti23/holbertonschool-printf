#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * print_c - Prints character
 * @c_list: character
 * Return: 1: The lenght of a char
 */

int print_c(va_list c_list)
{
	char s;

	s = va_arg(c_list, int);
	_putchar(s);
	return (1);
}

/**
 * print_s - Prints strings
 * @s_list: Strings
 * Return: The lenght of the string
 */

int print_s(va_list s_list)
{
	int count;
	char *str = va_arg(s_list, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}

/**
 * print_i - Print integer
 * @i_list: Int to print
 * Return: Numbers of integers printed
 */

int print_i(va_list i_list)
{
	long int number = (long int)va_arg(i_list, int);
	long int nr_weight = 1;
	long int tmp = number;
	int nr_digits = 1;

	if (number < 0)
	{
		_putchar('-');
		nr_digits++;
		tmp = tmp * -1;
		number = number * -1;
	}
	while (tmp > 9)
	{
		tmp = tmp / 10;
		nr_weight = nr_weight * 10;
		nr_digits++;
	}
	while (nr_weight > 0)
	{
		_putchar('0' + (number / nr_weight) % 10);
		nr_weight = nr_weight / 10;
	}
	return (nr_digits);
}

/**
 * print_d - Print decimal
 * @d_list: Int to print
 * Return: Numbers of decimals printed
 */

int print_d(va_list d_list)
{
	long int number = (long int)va_arg(d_list, int);
	long int nr_weight = 1;
	long int tmp = number;
	int nr_digits = 1;

	if (number < 0)
	{
		_putchar('-');
		nr_digits++;
		tmp = tmp * -1;
		number = number * -1;
	}
	while (tmp > 9)
	{
		tmp = tmp / 10;
		nr_weight = nr_weight * 10;
		nr_digits++;
	}
	while (nr_weight > 0)
	{
		_putchar('0' + (number / nr_weight) % 10);
		nr_weight = nr_weight / 10;
	}
	return (nr_digits);
}
