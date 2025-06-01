#include <unistd.h>
#include "mul.h"

/**
 * _atoi - Converts a string to an integer (returns -1 on error).
 * @s: The string to convert.
 * Return: The integer value, or -1 on error.
 */
long _atoi(char *s)
{
	long i = 0, result = 0;

	if (!s || !s[0])
		return (-1);

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}

/**
 * print_number - Prints an integer using _putchar.
 * @n: The number to print.
 */
void print_number(long n)
{
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_error - Prints "Error\n" to stderr using _putchar.
 */
void print_error(void)
{
	char *msg = "Error\n";
	int i = 0;

	while (msg[i])
	{
		_putchar(msg[i]);
		i++;
	}
}

/**
 * main - Multiplies two positive numbers passed as arguments.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		print_error();
		return (98);
	}

	a = _atoi(argv[1]);
	b = _atoi(argv[2]);

	if (a < 0 || b < 0)
	{
		print_error();
		return (98);
	}

	print_number(a * b);
	_putchar('\n');
	return (0);
}

