#include "main.h"

/**
 * get_s - calculates the size to cast the argument
 * @format: formatted string to print the arguments to
 * @i: arguments to be printed.
 *
 * Return: Precision.
 */
int get_s(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
