#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
*function that produces output according to a format.
*Returns: the number of characters printed
*(excluding the null byte used to end output to strings)
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	const char *p;

	va_start(args, format);

	p = format;
	count = 0;
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
				case '%':
					count += print_percent();
					break;
				case 'c':
					count += print_char(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, const char *));
					break;
				case 'r':
					count += print_string("%r");
					break;
				case 'd':
				case 'i':
					count += print_number(va_arg(args, int));
					break;
				case 'u':
					count += print_unsigned(va_arg(args, unsigned int));
					break;
				case 'o':
					count += print_octal(va_arg(args, unsigned int));
					break;
				case 'x':
					count += print_hex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					count += print_hex(va_arg(args, unsigned int), 1);
					break;
				case 'b':
					count += print_binary(va_arg(args, unsigned int));
					break;
				default:
					putchar('%');
					putchar(*p);
					count += 2;
					break;
			}

		}
		else
		{
			putchar(*p);
			count++;
		}
		p++;
	}
	va_end(args);
	return (count);
}
