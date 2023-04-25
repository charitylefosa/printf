#include<stdio.h>
#include<stdarg.h>
#include"main.h"
/**
*
*
*
*/
void check(va_list args, buffet_t *output)
{
	va_end(args);
	write (1, output -> start, output -> len);
	free_buffer(output);
}

int run(const char *format, va_list args, buffet_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffet_t *, unsigned char, int, unsigned char);

	for (i = 0; *(format + 1); i++)
	{
		len = 0;
		if (*(format + 1) == '%')
		{

			flags = handle_flags(format + i + 1. &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1, &tmp);
			len = handle_length(format + i + tmp + 1, &tmp);
			f = handle_specifiers(format i + tmp + 1);
			if (f != NULL)
			{
				i += temp + 1;
				ret =+ f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
					ret = -1;
					break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	check(args, output);
	return (ret);
}


int _printf(const char *format)
{
	va_list args;
	buffer_t *output = init_buffet();

	if (format == NULL || output == NULL)
		return (-1);

	va_start(args, format);

	int ret = run(format, args, output);

	va_end(args);
	check(args, output);

	return (ret);
}
