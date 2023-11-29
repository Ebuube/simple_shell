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

	printf("trim: original str -> '%s'\n", *str);	/* test */
	if (str == NULL || *str == NULL || strlen(*str) == 0)
	{
		return (NULL);
	}
	string = *str;

	for (start = 0; string[start] && string[start] == DELIM; start++)
		;
	/* for (end = strlen(string) - 1; end > 0 && string[end] == DELIM; end--) */
	for (end = strlen(string); end > 0 && string[end - 1] == DELIM; end--)
		;

	/* size = (end == 0) ? 0 : end - start + 1; */
	size = (end == 0) ? 0 : end - start;
	printf("trim: [end] = %d;\t[start] = %d\n", end, start);	/* test */
	if (size == 0)
	{
		printf("trim: size is 0; str -> '%s'\n", *str);	/* test */
		free_str_safe(&*str);
		*str = NULL;
		return (NULL);
	}

	new = malloc((size + 1) * sizeof(char));
	if (new ==  NULL)
	{
		printf("trim: return new is NULL; string -> '%s'\n", string); /* test */
		return (NULL);
	}
	new = strncpy(new, string + start, size);
	new[size] = '\0';

	free_str_safe(&string);
	string = new;
	*str = string;

	printf("trim: return str -> '%s'\n", *str);	/* test */
	return (*str);
}
