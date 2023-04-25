#include <stdio.h>
#include <stdarg.h>
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
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				count += putchar(c);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				while (*s != '\0')
				{
					count += putchar(*s);
					s++;
				}
			}
			else if (*format == '%')
			{
				count += putchar('%');
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
