#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
    va_list arg_list;
    int j, i = 0, len = 0;

    print_data p_func[] = {
        {"c", pr_char},
        {"s", pr_string},
        {NULL, NULL}
    };

    va_start(arg_list, format);

    if (format == NULL)
        return (0);
    
    while (format != NULL && format[i] != '\0') {
        if (format[i] == '%' && format[i+1] != '%') 
        {
            j = 0;
            while (p_func[j].type != NULL)
            {
                if (format[i+1] == p_func[j].type[0])
                {
                    len += p_func[j].print(arg_list);
                    i++;
                }
                j++;
            }
        }
        else if (format[i] == '%' && format[i+1] == '%')
        {
            _putchar('%');
            len += 1;
            i++;
        }
        else 
        {
            _putchar(format[i]);
            len += 1;
        }
        i++;

    }

    va_end(arg_list);
    return (len);    
}

int main(void)
{
    _printf("This is it %s", "Hello World\n");

    return (0);
}