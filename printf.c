#include "main.h"
#include <stdlib.h>

/**
 * _printf - Function that prints with a format
 * @format: format passed to printf
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list mylist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(mylist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = check_formats(&format[i + 1]);
		if (f != NULL)
		{
			count += f(mylist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(mylist);
	return (count);
}
