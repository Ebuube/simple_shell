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
	if (args == NULL && args[0] == NULL)
	{
		return (SHELL.BUILTIN_FAILURE);
	}
	errno = SHELL.END_SHELL;

	if (args[1] == NULL)
	{
		return (SHELL.BUILTIN_SUCCESS);
	}

	SHELL.LAST_EXIT_STATUS = atoi(args[1]);

	return (SHELL.BUILTIN_SUCCESS);
}
