#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int h_print(const char *format, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


int print_character(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_per(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_uns(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexu(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexul(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_non(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_flag(const char *format, int *i);
int get_w(const char *format, int *i, va_list list);
int get_prec(const char *format, int *i, va_list list);
int get_s(const char *format, int *i);

int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int handle_write(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_numb(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_p(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_s);

int write_uns(int is_neg, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int is_p(char);
int append_hex(char, char[], int);
int is_dig(char);

long int size_number(long int num, int size);
long int size_unsgnd(unsigned long int num, int size);

#endif 
