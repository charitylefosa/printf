#include<stdarg.h>
#include<unistd.h>
#include<string.h>
/**
*_printf- prints output according to format
*@format: format string
*
*Return: number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	char str;

	va_start(args, format);

	while (*format)
	{
		str = *format++;
		if (str == '%')
		{
			str = *format++;
			if (c == 'c')
			{

	
		}
		else
		{
			count += write(1, &format[i - 1]);
		}
	}
	va_end(args);
	return (count);
}
