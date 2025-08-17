#include <stdlib.h>
#include <stdio.h>

/**
 * regex_match - checks match between a string and a pattern
 * @str: string to be checked
 * @pattern: regular expression to compare to str
 * Return: 1 if pattern matches str, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*(pattern + 1) == '*')
	{

		if (regex_match(str, pattern + 2))
			return (1);

		if (*str != '\0' && (*str == *pattern))
			return (regex_match(str + 1, pattern));

		if (*str != '\0' && *pattern == '.')
			return (regex_match(str + 1, pattern));

		return (0);
	}

	if (*str != '\0' && (*str == *pattern))
		return (regex_match(str + 1, pattern + 1));

	if (*str != '\0' && *pattern == '.')
		return (regex_match(str + 1, pattern + 1));

	return (0);

}
