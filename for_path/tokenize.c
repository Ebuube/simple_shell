#include "shell.h"


/**
 * tokenize - create an argument vector from a delimited string
 * @str: string to work on
 * @delim: a set of bytes that delimit the string
 * Description: space and newline delimited entries
 * Return: the argument vector else, NULL on error
 */
char **tokenize(char *str, const char *delim)
{
	char **toks = NULL, *tmp = NULL;
	char *DELIM = " \n";
	bool incomplete = false;
	size_t i = 0, tok_count = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	DELIM = (delim == NULL) ? DELIM : (char *)delim;

	tok_count = count_tok(str, DELIM);
	toks = malloc((tok_count + 1) * sizeof(char *));
	/* extra for the ending NULL argument */
	if (toks == NULL)
	{
		return (NULL);
	}

	for (i = 0, tmp = str; i < tok_count; i++, tmp = NULL)
	{
		toks[i] = strtok(tmp, DELIM);
		if (toks[i] == NULL && i < tok_count)
		{
			incomplete = true;
			break;
		}
	}

	if (incomplete == true)
	{
		toks = realloc(toks, (i + 1) * sizeof(char *));
		if (toks == NULL)
			return (NULL);
	}
	toks[i] = NULL;	/* terminate the vector */

	return (toks);
}


/**
 * count_tok - count the number of tokens in a string
 * @str: to search
 * @delim: a string of delimiters to look out for
 *
 * Return: the number of tokens found, else -1 on error
 */
int count_tok(const char *str, const char *delim)
{
	size_t i = 0, count = 0;

	if (str == NULL || delim == NULL)
	{
		return (-1);
	}

	for (i = 0; str[i];)
	{
		if (!strchr(delim, str[i]))
		{/* token found */
			for (; str[i] && !strchr(delim, str[i]); i++)
				;
			count++;
		}
		else
			i++;
	}

	return (count);
}
