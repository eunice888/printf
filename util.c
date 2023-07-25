#include "main.h"

/**
 * is_p - is character printable
 * @c: character
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_p(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hex - hexadecimal code to buffer
 * @buffer: array of characters.
 * @i: index to start appending.
 * @ascii_code: ASSCI code
 * Return: Always 3
 */
int append_hex(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_dig - is character a digit
 * @c: character 
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_dig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * size_number - casts a number to the specified size
 * @num: number
 * @size: number indicating the type
 *
 * Return: casted value of number
 */
long int size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
