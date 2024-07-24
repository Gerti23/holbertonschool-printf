#include "main.h"
#include <stdarg.h>
#include <stdlib.h>


int pr_char(va_list char_list)
{
	char letter;

	letter = va_arg(char_list, int);
	_putchar(letter);

	return (1);	
}


int pr_string(va_list string_list)
{
	int i;
	char *word;

	word = va_arg(string_list, char*);
	if (word == NULL)
		word = "(null)";

	for (i = 0; word[i] != '\0'; i++)
		_putchar(word[i]);

	return (i);
}