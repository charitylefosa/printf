#include "main.h"
int print_c(va_list args, int count)
{
	int c = va_arg(args, int);
	count += putchar(c);
	return (count);
}

int print_s(va_list args, int count)
{
	char *s = va_arg(args, char*);

	while (*s)
	{
		count += putchar(*s);
		s++;
	}
	return (count);
}

int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		/*{'i', print_i},*/
		{'s', print_s},
		{'c', print_c},
		/*{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}*/
		};

	int flags = 3;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
