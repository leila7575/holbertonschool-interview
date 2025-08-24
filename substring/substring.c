#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * find_index - finds index of a word in array
 * @words: array containing unique words
 * @count: number of unique words in array
 * @word: word to search in array
 * @len: length of the word
 * Return: index of word, -1 if not found
 */
int find_index(const char **words, int count, const char *word, int len)
{
	for (int i = 0; i < count; i++)
	{
		if (strncmp(words[i], word, len) == 0 && words[i][len] == '\0')
			return (i);
	}
	return (-1);
}

/**
 * check_substring - checks if substring is valid
 * @s: string to check
 * @start_index: start index of substring
 * @unique_words: array of unique words
 * @unique_count: number of unique_words
 * @word_len: length of words
 * @required_counts: ocurrences for each word
 * @nb_words: number of words in subtring
 * Return: 1 if string is valid, 0 otherwise
 */
int check_substring(
	const char *s, int start_index, const char **unique_words,
	int unique_count, int word_len, int *required_counts, int nb_words
)
{
	int *found_counts = malloc(unique_count * sizeof(int));

	if (!found_counts)
		return (0);
	for (int i = 0; i < unique_count; i++)
		found_counts[i] = 0;
	for (int i = 0; i < nb_words; i++)
	{
		int pos = start_index + i * word_len;
		int word_index = find_index(unique_words, unique_count, s + pos, word_len);

		if (word_index == -1)
		{
			free(found_counts);
			return (0);
		}
		found_counts[word_index]++;
		if (found_counts[word_index] > required_counts[word_index])
		{
			free(found_counts);
			return (0);
		}
	}
	for (int i = 0; i < unique_count; i++)
	{
		if (found_counts[i] != required_counts[i])
		{
			free(found_counts);
			return (0);
		}
	}
	free(found_counts);
	return (1);
}

/**
 * find_substring - finds all starting indices of substring
 * @s: string to search in
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to store number of results
 * Return: array of starting indices, or NULL
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int s_len, word_len, substring_len, unique_count = 0,
	int *required_counts, *temp_results, *results, i;
	const char **unique_words;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	substring_len = nb_words * word_len;
	if (substring_len > s_len || word_len == 0)
		return (NULL);
	unique_words = malloc(nb_words * sizeof(char *));
	required_counts = malloc(nb_words * sizeof(int));
	if (!unique_words || !required_counts)
	{
		free(unique_words);
		free(required_counts);
		return (NULL);
	}
	for (i = 0; i < nb_words; i++)
		required_counts[i] = 0;
	for (i = 0; i < nb_words; i++)
	{
		int idx = find_index(unique_words, unique_count, words[i], word_len);

		if (idx == -1)
		{
			unique_words[unique_count] = words[i];
			required_counts[unique_count++] = 1;
		}
		else
			required_counts[idx]++;
	}
	temp_results = malloc((s_len - substring_len + 1) * sizeof(int));
	if (!temp_results)
	{
		free(required_counts);
		free(unique_words);
		return (NULL);
	}
	for (i = 0; i <= s_len - substring_len; i++)
	{
		if (check_substring
			(
			s, i, unique_words, unique_count, word_len, required_counts, nb_words
		))
			temp_results[(*n)++] = i;
	}
	free(required_counts);
	free(unique_words);
	if (*n == 0)
	{
		free(temp_results);
		return (NULL);
	}
	results = malloc(*n * sizeof(int));
	if (!results)
	{
		free(temp_results);
		*n = 0;
		return (NULL);
	}
	for (i = 0; i < *n; i++)
		results[i] = temp_results[i];
	free(temp_results);
	return (results);
}
