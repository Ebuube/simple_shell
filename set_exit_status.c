#include "shell.h"

/**
 * set_exit_status - sets the exit status of the last executed command
 * @status: status of last command
 *
 * Return: 1 if set else 0
 */
int set_exit_status(pid_t status)
{
	char *var = NULL;
	int i = 0, length = 0, dummy = 0;
	const int BASE = 10;

	if (status != SHELL.LAST_EXIT_STATUS)
	{
		fprintf(stderr,
			"Warning: Last exit status differs from argument\n");
		fprintf(stderr, "Last exit status: %d\n", SHELL.LAST_EXIT_STATUS);
		fprintf(stderr, "Argument: %d\n", status);
	}

	/* get the number of characters */
	for (i = 0, dummy = status / BASE; dummy > 0; i++)
		dummy = dummy / BASE;
	length = i + 2;		/* Extra one for null byte */
	var = malloc(length * sizeof(char));
	if (var == NULL)
	{
		return (0);
	}
	sprintf(var, "%d", status);
	printf("set_exit_status: status as string '%s'\n", var);

	return (1);
}
