#include "shell.h"

/**
 * _exit_shell - terminate the shell
 * @args: a list of arguments to exit as well as the 'exit' as first element
 *
 * Description: Usage -- exit [status]
 * Return: Success if all was processed fine, else Failure
 */
pid_t _exit_shell(const char **args)
{
	int status = 0, i = 0;
	const int EXIT_DEFAULT = 2;

	if (args == NULL && args[0] == NULL)
	{
		return (SHELL.BUILTIN_FAILURE);
	}
	errno = SHELL.END_SHELL;

	if (args[1] == NULL)
	{
		return (SHELL.BUILTIN_SUCCESS);
	}

	for (i = 0; args[1][i] != '\0'; i++)
	{
		if (isalpha(args[1][i]))
			status = -1;
		else
			status = atoi(args[1]);
	}
	if (status < 0)
	{
		fprintf(stderr, "%s: 1: exit: Illegal number: %s\n",
			ERR_PROMPT, args[1]);
		status = EXIT_DEFAULT;
	}
	SHELL.LAST_EXIT_STATUS = status;

	return (SHELL.BUILTIN_SUCCESS);
}
