#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
*@s : string to be printed
*Return: 1
*/
int print_string(const char *s)
{
	int count;

	count = 0;
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


/* prints a signed decimal number */

int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		putchar('-');
		n = -n;
		count++;
	}
	if (n / 10)
	{
		count += print_number(n / 10);
	}
	putchar(n % 10 + '0');
	return (count + 1);
}

/* prints an unsigned decimal number */

int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
	{
		count += print_unsigned(n / 10);
	}
	putchar(n % 10 + '0');
	return (count + 1);
}

/* prints an octal number */

int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
	{
		count += print_octal(n / 8);
	}
	putchar (n % 8 + '0');
	return (count +1);}

/* prints hexidecimal number */

int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	int digit = n % 16;

	if (n / 16)
	{
		count += print_hex(n / 16, uppercase);
	}
	if (digit < 10)
	{
		putchar(digit + '0');
	}
	else
	{
		putchar(digit - 10 + (uppercase ? 'A' : 'a'));
	}
	return (count + 1);
}

/* prints a binary number */

int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
	{
		count += print_binary(n / 2);
	}
	putchar(n % 2 + '0');
	return (count + 1);
}


