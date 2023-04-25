#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <stdio.h>
/**
*print_c - prints a character
*@args: characters to be printed in va_list
*Return: number of characters printed
*/
int print_c(va_list args)
{
	char c = va_arg(args, int);
	int count = 1;
	putchar(c);
	return (count);
}

/**
*print_s- prints a string
*@args: characters to be printed in va_list
*Return: number of characters printed
*/
int print_s(va_list args)
{
	char *s = va_arg(args, char *);
	int l;

	if (s == NULL)
		s = "(null)";
	l = 0;
	while(s[l])
		l++;
	write(1, s, l);
	return (l);
}

/**
*print_p- prints a percent sign
*Return: number of characters printed
*/
int print_p(void)
{
	return (putchar('%'));
}

/**
*h_specifier- handles conversion specifiers
*@args: arguments
*@specifier: specifiers to be handles
*Return: count
*/
int h_specifier(char specifier, va_list args)
{
	int count;

	count = 0;
	switch (specifier)
	{
		case 'c':
		{
			count = print_c(args);
			break;
		}
		case 's':
		{
			count = print_s(args);
			break;
		}
		case '%':
		{
			count += print_s(args);
			break;
		}
		default:
		{
			putchar ('%');
			putchar(specifier);
			count += 2;
			break;
		}
	}
	return (count);
}

/**
*_printf- produces output according to a format
*@format: string that is composed of zero or more directives
*Return: count
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i, count;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	count = 0;
	i = 0;
	while (format[0])
	{
		if (format[i] == '%')
		{
			i++;
			count = h_specifier(format[i], args);
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
