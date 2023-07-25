#include "main.h"

/**
 * print_uns - Prints an unsigned number
 * @types: the list  of arguments
 * @buffer: the buffer array to handle print
 * @flags:  calculate the active flags
 * @width: width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of characters printed
 */
int print_uns(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_uns(0, i, buffer, flags, width, precision, size));
}

/**
 * print_oct - Prints an unsigned number in octal notation
 * @types: the list  of arguments
 * @buffer: the buffer array to handle print
 * @flags:  calculate the active flags
 * @width: width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of characters printed
 */
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_uns(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hex - prints an unsigned number in hexadecimal notation
 * @types: the list  of arguments
 * @buffer: the buffer array to handle print
 * @flags:  calculate the active flags
 * @width: width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of characters printed
 */
int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexul(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexu - Prints an unsigned number in upper hexadecimal notation
 * @types: the list  of arguments
 * @buffer: the buffer array to handle print
 * @flags:  calculate the active flags
 * @width: width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of characters printed
 */
int print_hexu(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexul(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexul - Prints a hexadecimal number in lower or upper
 * @types: list the of arguments
 * @map_to: an array of values to map the number
 * @buffer: the buffer array to handle print
 * @flags:  calculate the active flags
 * @flagc: calculate the active flags
 * @width: width
 * @precision: the precision specification
 * @size: the size specifier
 * @size: the size specification
 * Return: the number of characters printed
 */
int print_hexul(va_list types, char map_to[], char buffer[],
	int flags, char flagc, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flagc;
		buffer[i--] = '0';
	}

	i++;

	return (write_uns(0, i, buffer, flags, width, precision, size));
}
