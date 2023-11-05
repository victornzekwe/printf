#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct format_specifier - format specifier
 * @fmt_sign: fmt sign
 * @fmt_func_ptr: fmt func ptr
 */

typedef struct format_specifier
{
	char fmt_sign;
	void (*fmt_func_ptr)(char, va_list, int *, char);
} fmt;

int _putchar(char c);
int _printf(const char *format, ...);
int print_fmt(const char *format, va_list args,
int *count, fmt fmt_specs[]);
void char_print(char flag, va_list args, int *count, char space);
void string_print(char flag, va_list args, int *count, char space);
void int_print(char flag, va_list args, int *count, char space);
void dec_print(char flag, va_list args, int *count, char space);
void bin_print(char flag, va_list args, int *count, char space);
void uint_print(char flag, va_list args, int *count, char space);
void oct_print(char flag, va_list args, int *count, char space);
void hex_print(char flag, va_list args, int *count, char space);
void cap_hex_print(char flag, va_list args, int *count, char space);
void str_hex_print(char flag, va_list args, int *count, char space);
void ptr_print(char flag, va_list args, int *count, char space);
void zero(char *nil, int *count);
bool handle_fmt_spec(char fmt_char, va_list args,
int *count, fmt fmt_specs[], char *flag, char *space);

#endif
