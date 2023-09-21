#include "shell.h"

/**
 * resolve_path - find the absolute path name of a program
 * @prg: name of program
 *
 * Return: the absolute path name,
 * else return NULL on error or if not found.
 */
char *resolve_path(const char *prg)
{
	char *abs_path = NULL, *new = NULL;
	dir_list_t *head = NULL, *tmp = NULL;

	if (prg == NULL)
	{
		return (NULL);
	}

	head = path_list();
	if (head == NULL)
	{
		return (NULL);
	}

	for (tmp = head; tmp != NULL; tmp = tmp->next)
	{
		abs_path = abspath(tmp->dir, prg);	/* modified */
		if (abs_path != NULL)
		{
			new = strdup(abs_path);
			if (new == NULL)
			{
				free(abs_path);
				return (NULL);
			}
			free(abs_path);
			abs_path = new;
			break;
		}
	}
	/* Clean up */
	free_dir_list(&head);

	return (abs_path);
}

/**
 * abspath - Create the absolute path name of a file in a directory if present
 * @dir: name of directory to search
 * @file: file to locate
 *
 * Description: this function is not recursive
 * i.e. it does not search internal directories
 *
 * Return: concatenation of directory name and file name if found, else NULL
 */
char *abspath(const char *dir, const char *file)
{
	struct stat statbuf;
	char *absolute = NULL;
	int status = 0;
	size_t size = 0;

	if (dir == NULL || file == NULL)
	{
		return (NULL);
	}

	size = strlen(dir) + strlen(FILE_DELIM) + strlen(file) + 1;
	absolute = malloc(size * sizeof(char));
	if (absolute == NULL)
	{
		return (NULL);
	}
	if (strcpy(absolute, dir) == NULL)
	{
		free(absolute);
		return (NULL);
	}
	if (strcat(absolute, FILE_DELIM) == NULL)
	{
		free(absolute);
		return (NULL);
	}
	if (strcat(absolute, file) == NULL)
	{
		free(absolute);
		return (NULL);
	}

	status = stat(absolute, &statbuf);
	if (status != 0)
	{/* Could not find file */
		free(absolute);
		return (NULL);
	}

	return (absolute);
}


/**
 * search_dir - recursively search for a file in a directory
 * @dir_name: name of directory to search
 * @filename: the file to look for
 *
 * Description: The name of a directory is never returned as
 * the absolute path of a file passed to the function.
 * Return: the absolute name of the file if found,
 *
 * else NULL
 */
char *search_dir(const char *dir_name, const char *filename)
{
	DIR *dir = NULL;
	struct dirent *entry = NULL;
	char *abs_name = NULL;
	const char *CUR_WD = ".", *P_WD = "..";

	if (dir_name == NULL || filename == NULL)
	{
		return (NULL);
	}
	dir = opendir(dir_name);
	if (dir == NULL)
	{
		return (NULL);
	}

	for (entry = readdir(dir); entry != NULL; entry = readdir(dir))
	{
		if (entry->d_type == DT_DIR &&
			((strcmp(entry->d_name, CUR_WD) == 0) ||
			 (strcmp(entry->d_name, P_WD) == 0)))
		{
			continue;
		}
		if (entry->d_type == DT_DIR)
		{/* recursive searching */
			abs_name = search_dir(entry->d_name, filename);
		}
		else if (strcmp(entry->d_name, filename) == 0)
		{
			abs_name = entry->d_name;
			break;
		}
	}

	closedir(dir);
	return (abs_name);
}
