#include "main.h"
/**
* get_print - selects the right printing function according to specifier
* @s: character that holds the conversion specifier
*
* Return: a pointer to the matching printing function
*/

int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] =	{
		{'s', print_string},
		{'c', print_char},
		{'%', print_percent}
		};
	int flags;
	register int i;

	flags = 3;
	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
