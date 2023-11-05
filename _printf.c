#include "main.h"

/**
 * _putchar - putchar function
 * @c: character
 * Return: 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - printf function
 * @format: format
 * Return: no of chars
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	fmt fmt_specs[] = {
		{'c', char_print}, {'s', string_print}, {'d', dec_print},
		{'i', int_print}, {'b', bin_print}, {'u', uint_print},
		{'o', oct_print}, {'x', hex_print}, {'X', cap_hex_print},
		{'S', str_hex_print}, {'p', ptr_print}, {'\0', NULL}
	};

	count = 0;
	va_start(args, format);

	if (format != NULL)
	{
		if (print_fmt(format, args, &count, fmt_specs) == -1)
			return (-1);
	}
	else
		return (-1);

	va_end(args);
	return (count);
}

/**
 * print_fmt - _printf helper function
 * @format: format
 * @args: args
 * @count: count
 * @fmt_specs: fmt specs
 * Return: num of char printed
 */

int print_fmt(const char *format,
	va_list args, int *count, fmt fmt_specs[])
{
	int i;
	char flag = '\0';
	char space = '\0';

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%') /* check for fmt spec */
		{ _putchar(format[i]);
			(*count)++; }
		else /* start fmt spec */
		{
			i++;
			if (format[i] == '+' || format[i] == '-' || format[i] == '#')
			{ flag = format[i];
				i++;
				if (format[i] == ' ')
					i++;
			}
			else if (format[i] == ' ')
			{ space = format[i];
				i++;
				if (format[i] == '+' || format[i] == '-' || format[i] == '#')
				{ flag = format[i];
					i++; }
			}
			if (format[i] == '\0')
				return (-1);
			if (!handle_fmt_spec(format[i], args,
				count, fmt_specs, &flag, &space))
			{ _putchar('%');
				_putchar(format[i]);
				(*count) += 2;
			}
		}
	}
	return (0);
}

/**
 * handle_fmt_spec - print_fmt helper function
 * @fmt_char: fmt char
 * @args: args
 * @count: count
 * @fmt_specs: fmt specs
 * @flag: flags
 * @space: space
 * Return: true/ false
 */

bool handle_fmt_spec(char fmt_char, va_list args, int *count,
	fmt fmt_specs[], char *flag, char *space)
{
	int j;

	if (fmt_char == '%')
	{
		_putchar(fmt_char);
		(*count)++;
		return (true);
	}
	for (j = 0; fmt_specs[j].fmt_sign != '\0'; j++)
	{
		if (fmt_char == fmt_specs[j].fmt_sign)
		{
			fmt_specs[j].fmt_func_ptr(*flag, args, count, *space);
			return (true);
		}
	}
	return (false);
}
