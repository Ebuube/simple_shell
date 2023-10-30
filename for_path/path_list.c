#include "path_list.h"

/**
 * path_list - build a linked list of the PATH directories
 *
 * Return: pointer to a dir_list_t list of PATH directories,
 * else NULL
 */
dir_list_t *path_list(void)
{
	char *path = NULL;
	char **dir_array = NULL;
	const char *PATH_VAR = "PATH", *PATH_DELIM = ":";
	dir_list_t *head = NULL;
	unsigned int i = 0;

	path = _getenv(PATH_VAR);
	if (path == NULL)
	{
		return (NULL);
	}
	path = strdup(path);
	if (path == NULL)
	{
		return (NULL);
	}

	dir_array = tokenize(path, PATH_DELIM);
	if (dir_array == NULL)
	{
		return (NULL);
	}

	for (i = 0; dir_array[i] != NULL; i++)
	{
		add_dir_list_node(&head, dir_array[i]);
	}

	free(dir_array);
	free(path);

	return (head);
}
