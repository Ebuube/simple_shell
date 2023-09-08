#include "shell.h"

/**
 * sh_loop - loops through to emulate a UNIX Commandline Interpreter
 *
 * Return: nothing
 */
void sh_loop(void)
{
	char *line = 0;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			printf(SHELL_PROMPT);
		}

		line = sh_readline();

		/* test */
		if (!interactive && line[0] == '\0')
		{/* Once end of file is reached */
			break;

			/* Clean up */
			free(line);
		}

		if (line)
			sh_execute(line);

		/* Clean up */
		if (!line)
			free(line);
		fflush(STDIN_FILENO);
		errno = 0;
	}
}
