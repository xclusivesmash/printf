#ifndef MAIN_H
#define MAIN_H

/* libraries */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* MACROS */
#define __void__(x) (void)(x)
#define STDOUT 1
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: The format.
 * @fn: The function associated.
 * Description: none.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

/* function prototypes */
int _printf(const char *format, ...);
int _strlen(char *s);
int _pow(int x, int y);
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *fmt, int *i,
va_list store, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list store);
int _precision(const char *format, int *i, va_list store);
int _size(const char *format, int *i);
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
