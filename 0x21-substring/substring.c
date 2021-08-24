#include "substring.h"

/**
 * find_substring - Finds all the possible substrings containing a list of
 * words, within a given string.
 * @s: String to scan
 * @words: Array of words all substrings must be a concatenation arrangement of
 * @nb_words: Number of elements in the array words
 * @n: Holds the address at which to store the number of elements
 * in the returned array.
 * Return:  an allocated array, storing each index in s, at which a
 * substring was found. If no solution is found, NULL can be returned
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, wordslen, actualindex, count, compare, i, j, k;
	int *arrayindex, *match;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);
	s_len = strlen(s);
	wordslen = strlen(words[0]);
	arrayindex = malloc(s_len * sizeof(int));
	if (!arrayindex)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);
	for (i = count = 0; i <= s_len - nb_words * wordslen; i++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				actualindex = i + j * wordslen;
				compare = strncmp(s + actualindex, *(words + k), wordslen);
				if (!*(match + k) && !compare)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(arrayindex + count) = i, count += 1;
	}
	free(match);
	*n = count;
	return (arrayindex);
}
