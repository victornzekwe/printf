#include "main.h"

/**
 * oct_print - oct print
 * @flag: flag
 * @args: args
 * @count: count
 * @space: space
 */

void oct_print(char flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int o, i, o_len, num;
	int j;
	char *digits;

	o = va_arg(args, unsigned int);
	num = o;
	o_len = 0;
	while (o / 8 != 0)
	{
		o_len++;
		o = o / 8;
	}
	o_len++;
	digits = malloc(sizeof(char) * (o_len + 1));
	if (digits == NULL)
		return;
	i = 0;
	while (num / 8 != 0)
	{
		digits[i] = (num % 8) + '0';
		num = num / 8;
		i++;
	}
	digits[i] = (num % 8) + '0';
	if (flag == '#' && num != 0)
	{ _putchar('0');
		(*count)++; }
	for (j = i; j >= 0; j--)
	{
		_putchar(digits[j]);
		(*count)++;
	}
	free(digits);
}

/**
 * bin_print - bin print
 * @flag: flag
 * @args: args
 * @count: count
 * @space: space
 */

void bin_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int b, i, b_len, num;
	int j;
	char *digits;

	b = va_arg(args, unsigned int);
	num = b;
	b_len = 0;
	while (b / 2 != 0)
	{
		b_len++;
		b = b / 2;
	}
	b_len++;
	digits = malloc(sizeof(char) * (b_len + 1));
	if (digits == NULL)
	{
		return;
	}
	i = 0;
	while (num / 2 != 0)
	{
		digits[i] = (num % 2) + '0';
		num = num / 2;
		i++;
	}
	digits[i] = (num % 2) + '0';
	for (j = i; j >= 0; j--)
	{
		_putchar(digits[j]);
		(*count)++;
	}
	free(digits);
}

/**
 * ptr_print - ptr print
 * @flag: flag
 * @args: args
 * @count: count
 * @space: space
 */

void ptr_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned long int ptr, ptr_value;
	int i, j, ptr_len;
	char hex_digits[] = "0123456789abcdef";
	char *nil = "(nil)";
	char *hex_str;

	ptr = (unsigned long int)va_arg(args, void *);
	if (ptr != 0)
	{
		ptr_value = ptr;
		ptr_len = 0;
		while (ptr / 16 != 0)
		{ ptr_len++;
			ptr = ptr / 16; }
		ptr_len++;
		hex_str = malloc(sizeof(char) * (ptr_len + 1));
		if (hex_str == NULL)
			return;
		i = 0;
		while (ptr_value / 16 != 0)
		{ hex_str[i] = hex_digits[ptr_value % 16];
			ptr_value = ptr_value / 16;
			i++; }
		hex_str[i] = hex_digits[ptr_value % 16];
		_putchar('0');
		_putchar('x');
		(*count) += 2;
		for (j = i; j >= 0; j--)
		{ _putchar(hex_str[j]);
			(*count)++; }
		free(hex_str);
	}
	else
		zero(nil, count);
}

/**
 * zero - helper function to ptr_print
 * @nil: nil
 * @count: count
 */

void zero(char *nil, int *count)
{
	int k;

	for (k = 0; nil[k] != '\0'; k++)
	{
		_putchar(nil[k]);
		(*count)++;
	}
}
