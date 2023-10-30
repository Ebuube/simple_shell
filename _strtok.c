#include "_strtok.h"

/**
 * _strtok - split a string and return an array of each word of the string
 * @str: string to split
 * @delim: a set of bytes that delimit the string
 *
 * Description: The last element of the array is NULL
 *
 * Return: an array of words.
 * else return NULL on error or no word found.
 */
char **_strtok(char *str, const char *delim)
{
	char **ret = NULL;
	int num_tok = 0, c = 0;

	if (str == NULL || delim == NULL)
	{
		return (NULL);
	}

	num_tok = counttok(str, delim);	/* to be implemented */
	ret = malloc((num_tok * sizeof(char *)) + 1);

	for (c = 0; c < num_tok + 1; c++)
	{
		if (c == 0)
			ret[c] = strtok(str, delim);
		else
			ret[c] = strtok(NULL, delim);
		if (ret[c] == NULL)
			break;
	}

	return (ret);
}

/**
 * counttok - count the number of tokens in a string
 * @str: string to parse
 * @delim: a set of bytes that delimit the string
 *
 * Return: the number of tokens or -1 on failure
 */
int counttok(const char *str, const char *delim)
{
	int toks = 0, c = 0;

	if (str == NULL ||  delim == NULL)
	{
		return (-1);
	}

	for (c = 0; str[c] != '\0';)
	{
		if (index(delim, str[c]))
		{/* found delimiter */
			c++;
			continue;
		}

		/* Found token */
		for (; str[c] != '\0' && !(index(delim, str[c])); c++)
			;
		toks++;
	}

	return (toks);
}
