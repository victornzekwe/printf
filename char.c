#include "main.h"

/**
 * char_print - char print
 * @flag: flags
 * @args: args
 * @count: count
 * @space: space
 */

void char_print(char __attribute__ ((unused)) flag, va_list args,
		int *count, char __attribute__ ((unused)) space)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
	(*count)++;
}

/**
 * string_print - string print
 * @flag: flag
 * @args: args
 * @count: count
 * @space: space
 */

void string_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	char *s;
	int i;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		(*count)++;
	}
}
