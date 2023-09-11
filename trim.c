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
	char *new = NULL, *string = NULL;
	const char DELIM = ' ';
	unsigned int size = 0, start = 0, end = 0;

	if (str == NULL || *str == NULL || strlen(*str) == 0)
	{
		return (NULL);
	}
	string = *str;

	for (start = 0; string[start] && string[start] == DELIM; start++)
		;
	for (end = strlen(string) - 1; end > 0 && string[end] == DELIM; end--)
		;

	size = end - start + 1;
	
	if (end > size)
		size = end - start + 1;
	else    /* no good point found */
		size = 0;
	if (size == 0)
	{
		free(*str);
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

	free(string);
	string = new;
	*str = string;

	return (*str);
}
