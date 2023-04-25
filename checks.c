#include"main.h"
/**
*
*
*
*/
unsigned int (*handle_specifiers(const char))(va_list, buffet_t *, unsigned char, int, int, unsigned char)
{
	int i;

	converter_t converters[] =
	{
		{'c', convert_c},
		{'s', convert_s},
		{'%', convert_percent},
		{0, NULL}	};

	for (i = 0; converters[i].func, i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}
	return (NULL);
}
