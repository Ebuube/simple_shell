#include "shell.h"
#include "path_list.h"

/**
  * add_path - replace ordinary command with the actual command in PATH
  * @args: an array of arguments (strings)
  * @changed: assigns true / false to this value if it modifies argument
  *
  * Return: the restructured arguments, else NULL on error
  */
char **add_path(char **args, bool *changed)
{
	struct stat file_stats;
	char *cmd = NULL;
	const char *FILE_SEP = "/";
	dir_list_t *path = NULL, *tmp = NULL;

	if (args == NULL || args[0] == NULL)
	{
		return (NULL);
	}
	if (stat(args[0], &file_stats) == 0)
	{
		(*changed) = false;
		return (args);
	}

	path = path_list();
	for (tmp = path; tmp != NULL; tmp = tmp->next)
	{/* check path/cmd_name */
		cmd = strjoin(tmp->dir, FILE_SEP, args[0]);
		if (cmd == NULL)
			break;

		/* check if cmd is a file */
		if (stat(cmd, &file_stats) == 0)
			break;
		free(cmd);
		cmd = NULL;
	}
	free_dir_list(&path);

	if (cmd == NULL)
	{
		return (NULL);
	}
	args[0] = cmd;
	(*changed) = true;

	return (args);
}

/**
 * strjoin - joins two strings with a separator in between
 * @str1: first string
 * @sep: separator
 * @str2: second string
 *
 * Description: if the return value is not NULL, ensure to free it
 * Return: the concatenated string, else NULL
 */
char *strjoin(const char *str1, const char *sep, const char *str2)
{
	char *joined = NULL;
	int length = 0;

	if (str1 == NULL || sep == NULL || str2 == NULL)
	{
		return (NULL);
	}

	length = strlen(str1) + strlen(sep) + strlen(str2) + 1;
	joined = malloc(length * sizeof(char));
	if (joined != NULL)
	{
		if (!(strcpy(joined, str1)))
			return (NULL);
		if (!(strcat(joined, sep)))
			return (NULL);
		if (!(strcat(joined, str2)))
			return (NULL);
	}

	return (joined);
}
