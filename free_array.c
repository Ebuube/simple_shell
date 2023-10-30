#include "shell.h"

/**
 * free_array - free pointers in a 1D array of strings
 * @array: the head of the items to free
 *
 * Return: 0 on success, else -1 on failure
 */
int free_array(char **array)
{
	int a = 0;

	if (array == NULL)
	{
		return (-1);
	}
	for (a = 0; array && array[a] != NULL; a++)
	{
		if (array[a])
			free(array[a]);
	}

	return (0);
}
