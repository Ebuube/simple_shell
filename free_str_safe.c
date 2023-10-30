#include "shell.h"

/**
 * free_str_safe - free string and set it NULL
 * @str: address of string to free
 *
 * Return: nothing
 */
void free_str_safe(char **str)
{
	if (str == NULL || *str == NULL)
	{
		return;
	}
	free((*str));
	*str = NULL;
}
