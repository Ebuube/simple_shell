#include "shell.h"

/**
 * _env_builtin - list all environmental variables
 * @args: argument vector
 *
 * Return: exit status
 */
pid_t _env_builtin(const char **args)
{
	int i = 0;

	if (args == NULL)
	{/* No arguments necessary */
		;
	}

	for (i = 0; environ && environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

	return (SHELL.BUILTIN_SUCCESS);
}
