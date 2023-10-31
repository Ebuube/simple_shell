#include "shell.h"

/**
 * _unsetenv_btn - Unset an enviromental variable
 * @args: argument vector
 *
 * Description: unsetenv VARIABLE
 * Return: Success if all was processed fine, else FAILURE
 */
pid_t _unsetenv_btn(const char **args)
{
	int i = 0;
	const int MAX_ARGS = 2;

	if (args == NULL || args[0] == NULL)
	{
		return (SHELL.BUILTIN_FAILURE);
	}
	for (i = 0; args[1] && args[i] != NULL; i++)
		;

	if (i != MAX_ARGS)
	{
		fprintf(stderr, "%s: 1: unsetenv: Insufficient arguments\n",
				ERR_PROMPT);
		return (SHELL.BUILTIN_FAILURE);
	}

	if (unsetenv(args[1]) < 0)
	{
		return (SHELL.BUILTIN_FAILURE);
	}

	return (SHELL.BUILTIN_SUCCESS);
}
