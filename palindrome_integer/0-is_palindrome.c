#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"

/**
 * is_palindrome - checks if integer is a palidrome.
 *@n: integre to b checked.
 * Return: 1 if n is palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	char str[20];

	sprintf(str, "%ld", n);
	int length = strlen(str);

	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - i - 1])
			return (0);
	}
	return (1);
}
