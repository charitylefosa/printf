#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
*print_c- prints a character
*@args: arguments
*@count: count characters
*Return: count
*/
int print_c(va_list args, int count)
{
	int c = va_arg(args, int);

	count += putchar(c);
	return (count);
}

/**
*print_s- prints a string
*@args: arguments
*@count: count characters
*Return: count
*/
int print_s(va_list args, int count)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		count += putchar(*s);
		s++;
	}
	return (count);
}

/**
*h_specifier- handles conversion specifiers
*@args: arguments
*@specifier: specifiers to be handles
*Return: count
*/
int h_specifier(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
		{
			return (print_c(args, count));
		}
		case 's':
		{
			return (print_s(args, count));
		}
		case '%':
		{
			putchar('%');
			return (1);
		}
		default:
		{
			putchar('%');
			putchar(specifier);
			return (2);
		}
	}
}

/**
*_printf- produces output according to a format
*@format: string that is composed of zero or more directives
*Return: count
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += h_specifier(*format, args);
		}
		else
		{
			count += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
