#include "path_list.h"

/**
 * add_dir_list_node - add a new dir_list_t node at the end of a dir_list_t
 * list
 * @head: address of a pointer to the list's head
 * @dir_name: name of directory
 *
 * Return: address of new node, else NULL
 */
dir_list_t *add_dir_list_node(dir_list_t **head, const char *dir_name)
{
	dir_list_t *new = NULL, *tmp = NULL;

	if (head == NULL || dir_name == NULL)
	{
		return (NULL);
	}

	/* Creation and initializaton of new node */
	new = malloc(sizeof(dir_list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->dir = strdup(dir_name);
	if (new->dir == NULL)
	{
		return (NULL);
	}
	new->next = NULL;

	/* Linking of new node */
	if (*head == NULL)
		(*head) = new;
	else
	{
		for (tmp = *head; tmp->next != NULL;)
			tmp = tmp->next;

		tmp->next = new;
	}

	return (new);
}
