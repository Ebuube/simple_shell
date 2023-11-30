#include "shell.h"

/**
 * trim - remove the left and right whitespaces in a string
 * @str: address of string to modify
 *
 * Description: If trimmed, the string will be shorted and the unnecessary
 * bytes removed
 *
 * Return: the modified string else NULL on error
 */
char *trim(char **str)
{
	char *new = NULL, *string = NULL, comment = '#';
	const char DELIM = ' ';
	unsigned int size = 0, start = 0, end = 0;
	int comment_start = 0;

	if (str == NULL || *str == NULL || strlen(*str) == 0)
	{
		return (NULL);
	}
	string = *str;

	for (start = 0; string[start] && string[start] == DELIM; start++)
		;
	for (end = strlen(string); end > 0 && string[end - 1] == DELIM; end--)
		;

	comment_start = find_chr(string, comment);
	printf("trim: comment starts at index %d\n", comment_start);	/* test */
	end = (comment_start > 0) ? (unsigned int)comment_start - 1 : end; 
	printf("trim: end = %d\n", end);	/* test */
	size = (end == 0) ? 0 : end - start;
	if (size == 0)
	{
		free_str_safe(&*str);
		*str = NULL;
		return (NULL);
	}

	new = malloc((size + 1) * sizeof(char));
	if (new ==  NULL)
	{
		return (NULL);
	}
	new = strncpy(new, string + start, size);
	new[size] = '\0';

	free_str_safe(&string);
	string = new;
	*str = string;

	return (*str);
}

/**
 * find_chr - returns the index of the first occurrence of a character
 * in a string
 * @str: string to searchh
 * @c: character to match
 * Description: index starts from 0
 *
 * Return: index of character else -1 if not found
 * else -2 on error
 */
int find_chr(const char *str, const char c)
{
	char *index = NULL;
	int pos = 0;

	if (str == NULL)
	{
		return (-2);
	}

	index = strchr(str, c);
	if (index == NULL)
	{/* not found */
		return (-1);
	}
	pos = (int)(index - str);

	return (pos);
}
