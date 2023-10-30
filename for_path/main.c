#include "path_list.h"
#include <stdio.h>

/**
 * main - test path_list() function
 *
 * Return: Always 0 if successful
 */
int main(void)
{
	dir_list_t *head = NULL, *tmp = NULL;

	head = path_list();
	if (head == NULL)
	{
		fprintf(stderr, "Error in creating list\n");
		exit(EXIT_FAILURE);
	}

	printf("Directories under PATH\n");
	for (tmp = head; tmp != NULL; tmp = tmp->next)
		printf("%s\n", tmp->dir);
	free_dir_list(&head);

	return (0);
}
