#include "main.h"
/**
*get_flag- turns flag on if modifier is found
*@s: character holding flag specifier
*@f: pointer to struct that turns the flag on
*Return: 1 for flag on
*	0 otherwise
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
