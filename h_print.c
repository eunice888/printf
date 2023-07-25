#include "main.h"
/**
 * h_print - prints an argument based on its type
 * @format: formatted string to print the arguments to
 * @list: arguments to be printed
 * @ind: ind
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: 1 or 2;
 */
int h_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_characters = -1;
	format_t format_types[] = {
		{'c', print_character}, {'s', print_str}, {'%', print_per},
		{'i', print_integer}, {'d', print_integer}, {'b', print_bin},
		{'u', print_uns}, {'o', print_oct}, {'x', print_hex},
		{'X', print_hexu}, {'p', print_p}, {'S', print_non},
		{'r', print_rev}, {'R', print_rot13}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_characters);
}
