#include "main.h"

/**
*get_flag - turns on flags if _printf finds
*a flag modifier in string format
*@s: character that holds the flag specifier
*@f: pointer to struct flags
*/

int get_flag(char s, flags_t *f)
{
	int i = 0;
	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
