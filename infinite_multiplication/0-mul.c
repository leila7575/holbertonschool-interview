#include <stdlib.h>
#include "mul.h"

/**
 * is_digit_string - Check if string contains only digits
 * @s: string to check
 * Return: 1 if valid, 0 if not
 */
int is_digit_string(char *s)
{
	int i = 0;

	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Get length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_error - Print Error
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}

/**
 * perform_multiplication - Perform multiplication algorithm
 * @num1: first number
 * @num2: second number
 * @result: result array
 * @len1: length of num1
 * @len2: length of num2
 */
void perform_multiplication(char *num1, char *num2, int *result, int len1,
							int len2)
{
	int i, j, carry, n1, n2, sum;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}

		if (carry > 0)
			result[i + j + 1] += carry;
	}
}

/**
 * print_result - Print the multiplication result
 * @result: result array
 * @len: total length
 */
void print_result(int *result, int len)
{
	int i = 0;

	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		_putchar('0');
	else
	{
		while (i < len)
		{
			_putchar(result[i] + '0');
			i++;
		}
	}
}

/**
 * multiply - Multiply two number strings
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
	int len1, len2;
	int *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	if (len1 == 0 || len2 == 0)
	{
		_putchar('0');
		return;
	}

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		return;

	perform_multiplication(num1, num2, result, len1, len2);
	print_result(result, len1 + len2);
	free(result);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error();
		return (98);
	}

	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
	{
		print_error();
		return (98);
	}

	multiply(argv[1], argv[2]);
	_putchar('\n');
	return (0);
}

