#include "shell.h"

/**
 * sh_loop - loops through to emulate a UNIX Commandline Interpreter
 *
 * Return: nothing
 */
void sh_loop(void)
{
	char *line = NULL;
	int interactive = 0;
	UNUSED pid_t status = 0;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		line = NULL;
		if (interactive)
		{
			printf(SHELL_PROMPT);
		}

		line = sh_readline();

		if (line == NULL)
		{/* Error - or end of file */
			if (line)
				free(line);

			if (interactive)
				putchar('\n');
			break;
		}
		printf("line: '%s'\n", line);	/* test */

		if (line && strlen(line) > 0)
			status = sh_execute(line);

		/* Clean up */
		if (line)
			free(line);
		fflush(STDIN_FILENO);
		errno = 0;

		/* exit *
		if (!interactive && status == -1)
		{
			exit(EXIT_FAILURE);
		} */
	}
}
