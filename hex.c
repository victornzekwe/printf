#include "main.h"

/**
 * hex_print - hex print
 * @flag: flag
 * @args: args
 * @count: count
 * @space: space
 * hex - hex
 */

void hex_print(char flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int hex, i, hex_len, num;
	int j;
	char hex_digits[] = "0123456789abcdef";
	char *hex_str;

	hex = va_arg(args, unsigned int);
	num = hex;
	hex_len = 0;
	while (hex / 16 != 0)
	{ hex_len++;
		hex = hex / 16; }
	hex_len++;
	hex_str = malloc(sizeof(char) * (hex_len + 1));
	if (hex_str == NULL)
		return;
	i = 0;
	while (num / 16 != 0)
	{ hex_str[i] = hex_digits[num % 16];
		num = num / 16;
		i++; }
	hex_str[i] = hex_digits[num % 16];
	if (flag == '#' && num != 0)
	{ _putchar('0');
		_putchar('x');
		(*count) += 2; }
	/* print digits in reverse order */
	for (j = i; j >= 0; j--)
	{ _putchar(hex_str[j]);
		(*count)++; }
	free(hex_str);
}

/**
 * str_hex_print - str hex print
 * @flag: flag
 * @args: args
 * @count: pcount
 * @space: space
 */

void str_hex_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (str[i] < 16)
			{
				_putchar('0');
				_printf("%X", str[i]);
			}
			else
			{
				_printf("%X", str[i]);
			}
			(*count) += 4;
		}
		else
		{
			_putchar(str[i]);
			(*count)++;
		}
	}
}

/**
 * cap_hex_print - cap hex print
 * @flag: flag
 * @args: args
 * @count: count
 * @space: space
 */

void cap_hex_print(char flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int cap_hex, i, cap_hex_len, num;
	int j;
	char cap_hex_digits[] = "0123456789ABCDEF";
	char *cap_hex_str;

	cap_hex = va_arg(args, unsigned int);
	num = cap_hex;
	cap_hex_len = 0;
	while (cap_hex / 16 != 0)
	{
		cap_hex_len++;
		cap_hex = cap_hex / 16;
	}
	cap_hex_len++;
	cap_hex_str = malloc(sizeof(char) * (cap_hex_len + 1));
	if (cap_hex_str == NULL)
		return;
	i = 0;
	while (num / 16 != 0)
	{
		cap_hex_str[i] = cap_hex_digits[num % 16];
		num = num / 16;
		i++;
	}
	cap_hex_str[i] = cap_hex_digits[num % 16];
	if (flag == '#' && num != 0)
	{ _putchar('0');
		_putchar('X');
		(*count) += 2; }
	for (j = i; j >= 0; j--)
	{
		_putchar(cap_hex_str[j]);
		(*count)++;
	}
	free(cap_hex_str);
}
