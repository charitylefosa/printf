#include "main.h"

/**
*_printf - prints output according to format
*@format: format string contains characters and specifiers
*return length of formatted output string
*/

int _printf(const char *format, ...)
{
	int (*pfunction)(va_list, flags_t *);
	const char *p;
	va_list argu;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(argu, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format [0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunction = get_print(*p);
			count += (pfunction)
				? pfunction(argu, &flags)
				: printf("%%%c", *p);
		}
		else
			count += putchar(*p);
	}
	putchar(-1);
	va_end(argu);
	return(count);
}
