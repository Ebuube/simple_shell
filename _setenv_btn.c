#include "shell.h"

/**
 * _setenv_btn - set or modify an enviromental variable
 * @args: argument vector
 *
 * Description: setenv VARIABLE VALUE
 * Return: Success if all was processed fine, else FAILURE
 */
pid_t _setenv_btn(const char **args)
{
	int i = 0, modify = 1;
	const int MAX_ARGS = 3;

	if (args == NULL || args[0] == NULL)
	{
		return (SHELL.BUILTIN_FAILURE);
	}
	for (i = 0; args[1] && args[i] != NULL; i++)
		;

	if (i != MAX_ARGS)
	{
		fprintf(stderr, "%s: 1: setenv: Insufficient arguments\n",
				ERR_PROMPT);
		return (SHELL.BUILTIN_FAILURE);
	}

	if (setenv(args[1], args[2], modify) < 0)
	{
		return (SHELL.BUILTIN_FAILURE);
	}

	return (SHELL.BUILTIN_SUCCESS);
}
