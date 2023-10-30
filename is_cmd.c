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
	int length = 0;
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
		length = strlen(args[0]) + strlen("/") + strlen(tmp->dir) + 1;
		cmd = malloc(length * sizeof(char));
		if (cmd == NULL)
			return (NULL);
		if (!(strcpy(cmd, tmp->dir)))
			return (NULL);
		if (!(strcat(cmd, FILE_SEP)))
			return (NULL);
		if (!(strcat(cmd, args[0])))
			return (NULL);

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
