#include "main.h"
#include <stdlib.h>

/**
 * check_formats - checks for specifier
 * @format: specifier
 * Return: Pointer to function or NULL
 */

int (*check_formats(const char *format))(va_list)
{
	unsigned int i;
	print_t mystruct[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{NULL, NULL}
	};

	for (i = 0; mystruct[i].t != NULL; i++)
	{
		if (*(mystruct[i].t) == *format)
		{
			break;
		}
	}
	return (mystruct[i].f);
}
