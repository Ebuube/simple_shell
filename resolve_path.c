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
	char *abs_path = NULL;
	dir_list_t *head = NULL, *tmp = NULL;

	if (prg == NULL)
	{
		return (NULL);
	}

	printf("\n");	/* test */
	head = path_list();
	if (head == NULL)
	{
		return (NULL);
		printf("resolve_path: head -> %p\n", (void *)head);	/* test */
	}
	printf("resolve_path: head -> %p\n\thead->dir: '%s'\n", (void *)head, head->dir);	/* test */

	for (tmp = head; tmp != NULL; tmp = tmp->next)
	{
		printf("resolve_path: searching the directory -> '%s'\n", head->dir);	/* test */
		abs_path = search_dir(tmp->dir, prg);
		if (abs_path != NULL)
		{
			printf("resolve_path: abs_path -> '%s'\tLeaving loop\n", abs_path);	/* test */
			/* expecting abs_path will be deleted after this
			 * function is exited
			 *
			 * abs_path = strdup(abs_path);
			 * if (abs_path == NULL)
			 *	return (NULL);
			 */
			break;
		}
	}

	/* Clean up */
	free_dir_list(&head);

	printf("resolve_path: finally leaving function. abs_path = '%s'\n", abs_path);	/* test */
	return (abs_path);
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
	printf("\n");	/* test */
	dir = opendir(dir_name);
	if (dir == NULL)
	{
		printf("search_dir: could not open directory -> %p\n", (void *)dir);	/* test */
		return (NULL);
	}
	printf("search_dir: successfully opened the directory -> %p\n", (void *)dir);	/* test */

	for (entry = readdir(dir); entry != NULL; entry = readdir(dir))
	{
		printf("search_dir: accessing the entry -> '%s'\n", entry->d_name);	/* test */
		if (entry->d_type == DT_DIR &&
			((strcmp(entry->d_name, CUR_WD) == 0) || (strcmp(entry->d_name, P_WD) == 0)))
		{/* Don't do recursive search in Parent (..) and current (.) working directory aliases */
			continue;
		}
		if (entry->d_type == DT_DIR)
		{/* recursive searching */
			printf("search_dir: do recursive search in the directory -> '%s'\n", entry->d_name);	/* test */
			abs_name = search_dir(entry->d_name, filename);
		}
		else if (strcmp(entry->d_name, filename) == 0)
		{
			printf("search_dir: Found! entry -> '%s' equals given file '%s'\n", entry->d_name, filename);	/* test */
			abs_name = entry->d_name;
			break;
		}
	}

	closedir(dir);
	printf("search_dir: closing the directory -> %p\n", (void *)dir);	/* test */
	if (abs_name != NULL)
		printf("serach_dir: finally returning this as abs_name -> '%s'\n", abs_name);	/* test */
	else
		printf("search_dir: finally given file not found.\t abs_name -> %p\n", (void *)abs_name);	/*test */
	return (abs_name);
}
