#include "shell.h"

/**
 * _exit_shell - terminate the shell
 *
 * Return: exit status
 */
pid_t _exit_shell(void)
{
	errno = SHELL.END_SHELL;
	return (SHELL.BUILTIN_SUCCESS);
}
