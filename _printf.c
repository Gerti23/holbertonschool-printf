#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Character string composed of zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char ch;
    char *str;

    if (!format)
        return (-1);

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    ch = (char) va_arg(args, int);
                    count += write(1, &ch, 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str)
                        count += write(1, str, _strlen(str));
                    else
                        count += write(1, "(null)", 6);
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, &format[i], 1);
                    break;
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return (count);
}

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}
