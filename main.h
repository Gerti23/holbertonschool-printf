#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print - structure containing identifiers
 * @t: type to print
 * @f: function to print
 */

typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int (*check_formats(const char *format))(va_list);
int _printf(const char *format, ...);
int print_c(va_list ch_list);
int print_s(va_list s_list);
int print_i(va_list i_list);
int print_d(va_list d_list);

#endif
