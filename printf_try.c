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

	count = 0;
	while (*s)
	{
		putchar(*s++);
		count++;
	}
	return (count);
}

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
	return count + 1;
}

int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
	{
		count += print_unsigned(n / 10);
	}
	putchar (n % 10 + '0');
	return count + 1;
}

int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
	{
		count += print_octal(n / 8);
	}
	putchar(n % 8 + '0');
	return count + 1;
}

int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	int digit = n % 16;

	if (n / 16)
	{
		count += print_hex( n / 16, uppercase);
	}

	if (digit < 10)
	{
		putchar(digit + '0');
	}
	else
	{
		putchar(digit - 10 + (uppercase ? 'A' : 'a'));
	}
	return + 1;
}

int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
	{
		count += print_binary(n / 2);
	}
	putchar(n % 2 + '0');
	return count + 1;
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
