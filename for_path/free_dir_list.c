#include "path_list.h"

/**
 * free_dir_list - free a dir_list_t list
 * @head: address of pointer to head
 *
 * Return: nothing
 */
void free_dir_list(dir_list_t **head)
{
	dir_list_t *tmp = NULL;

	if (head == NULL || (*head) == NULL)
	{
		return;
	}

	for (tmp = (*head); tmp != NULL;)
	{
		(*head) = (*head)->next;
		free(tmp->dir);
		free(tmp);
		tmp = (*head);
	}
}
