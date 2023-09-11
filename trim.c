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

	if (str == NULL || *str == NULL)
	{
		return (NULL);
	}
	string = *str;

	printf("trim: str -> '%s'\n", string);	/* test */

	/* left trim */
	for (start = 0; string[start] && string[start] == DELIM; start++)
		;

	printf("start = %u\n", start);	/* test */

	for (end = strlen(string) - 1; end > 0 && string[end] == DELIM; end--)
		;

	printf("end = %u\n", end);	/* test */

	size = end - start + 1;
	
	printf("size = %u\n", size);	/* test */

	new = malloc((size + 1) * sizeof(char));
	if (new ==  NULL)
	{
		return (NULL);
	}

	new = strncpy(new, string + start, size);
	new[size] = '\0';

	printf("new -> '%s'\n", new);	/* test */

	free(string);
	string = new;

	return (string);
}
