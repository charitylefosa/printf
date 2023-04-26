#include<stdio.h>
#include <stdarg.h>
/**
*_print_percent - handles percent conversion specifiers
*@i: integer to be printed
*Return: 1
*
*/
int _print_percent(int i)
{
	i = '%';
	putchar(i);
	return (1);
}

/**
*_print_char_string - handles string and character conversion specifiers
*@args : va_list arguments
*Return: number of characters printed
*/
int _print_char_string(va_list args)
{
	int count;
	const char *s;

	count = 0;
	if (va_arg(args, int) == 's')
	{
		s = va_arg(args, const char *);
		while (*s)
		{
			putchar(*s++);
			count++;
		}
	}
	else
	{
		putchar(va_arg(args, int));
		count = 1;
	}
	return (count);
}
/**
*_print_nt - handles integer conversion specifiers
*@n: integer to be printed
*Return: number of characters
*
*/
int _print_int(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		putchar('-');
		n = -n;
		count++;
	}
	else
	{
		n = n;
	}
	if (n / 10)
	{
		count += _print_int(n / 10);
	}
	putchar(n % 10 + '0');
	count++;
	return (count);
}
/**
*handle_cov- handles conversion specifiers in va_list
*@args: arguments
*@p: conversion specifiers
*Return: count
*
*/
int handle_conv(va_list args, char p)
{
	int count;

	count = 0;
	switch (p)
	{
		case '%':
			count += _print_percent(va_arg(args, int));
			break;
		case 'c':
		case 's':
			count += _print_char_string(args);
			break;
		case 'd':
		case 'i':
			count += _print_int(va_arg(args, int));
			break;
		default:
			putchar('%');
			putchar(p);
			count += 2;
			break;
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
	char t;

	va_start(args, format);

	p = format;
	count = 0;
	while (*p)
	{
		if (*p == '%')
		{
			count += handle_conv(args, *(++p));

		}
		else
		{
			t = (char) *p;
			putchar(t);
			count++;
		}
		p++;
	}
	va_end(args);
	return (count);
}
