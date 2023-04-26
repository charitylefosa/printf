#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

typedef struct printhandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

int (*get_print(char s))(va_list, flags_t *);
int get_flag(char s, flags_t *f);
int _printf(const char *format, ...);
int _putchar(char c);
int print_percent(va_list l, flags_t *f);
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);




#endif 




