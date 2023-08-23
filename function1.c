#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints out an unsigned number
 * @types: List of arguments
 * @buffer: Set the buffer array to handle print
 * @flags:  Computes the active flags
 * @width: get the width
 * @precision: Set the precision specification
 * @size: Set the size of the specifier
 * Return: Numb of characters to be printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints out an unsigned number in octal notation
 * @types: list of arguments
 * @buffer: Set the buffer array to handle print
 * @flags:  Computes the active flags
 * @width: get the width
 * @precision: Set the precision specification
 * @size: Size of the specifier
 * Return: Num of characters to be printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

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

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints out an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Set a buffer array to handle print
 * @flags:  Computes the active flags
 * @width: get the width
 * @precision: Set the precision specification
 * @size: Size specifier
 * Return: Num of characters to be printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_octal - Prints out an unsigned number in octal notation
 * @types: list of arguments
 * @buffer: Set the buffer array to handle print
 * @flags:  Computes the active flags
 * @width: get the width
 * @precision: Set the precision specification
 * @size: Size of the specifier
 * Return: Num of characters to be printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints out a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Set the array of values to map the number to
 * @buffer: Set the buffer array to handle print
 * @flags:  Computes active flags
 * @flag_ch: Computes active flags
 * @width: get the width
 * @precision: Set the precision specification
 * @size: Set the size of the specifier
 * @size: Set the size specification
 * Return: Num of characters to be printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

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
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
