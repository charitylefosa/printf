#include<stdio.h>
#include <stdarg.h>
/**
*print_percent - handles percent conversion specifiers
*Return: 1
*
*/
int print_percent(void)
{
	putchar('%');
	return (1);
}
/**
*print_char - handles character conversion specifiers
*@c: character to be printed
*Return: 1
*/
int print_char(char c)
{
	putchar(c);
	return (1);
}
/**
*print_string - handles string conversion specifiers
*@s : string to be printed
*Return: 1
*/
int print_string(const char *s)
{
	int count;

	count =0;
	while (*s)
	{
		putchar(*s++);
		count++;
	}
	return (count);
}
/**
*_printf - count characters in string
*@format: character string composed of zero or more directives
*Return: count
*
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
				default:
					putchar(*p);
					count++;
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
