#include "shell.h"

/**
 * _env_builtin - list all environmental variables
 *
 * Return: exit status
 */
pid_t _env_builtin(void)
{
	int i = 0;

	for (i = 0; environ && environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

	return (SHELL.BUILTIN_SUCCESS);
}
