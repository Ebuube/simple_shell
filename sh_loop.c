#include "shell.h"

/**
 * sh_loop - loops through to emulate a UNIX Commandline Interpreter
 *
 * Return: nothing
 */
void sh_loop(void)
{
	char *line = NULL;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		line = NULL;
		if (interactive)
		{
			printf(SHELL_PROMPT);
		}

		line = sh_readline();

		if (line != NULL)
			sh_execute(line);

		/* Clean up */
		if (line)
			free(line);
		fflush(STDIN_FILENO);
		errno = 0;
	}
}
