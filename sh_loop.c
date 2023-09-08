#include "shell.h"

/**
 * sh_loop - loops through to emulate a UNIX Commandline Interpreter
 *
 * Return: nothing
 */
void sh_loop(void)
{
	char *line = 0;
	int interactive = 0;
	pid_t status = 0;
	char end_of_file = 0;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		if (interactive)
		{
			printf(SHELL_PROMPT);
		}

		end_of_file = EOF + 1;
		line = sh_readline(&end_of_file);

		if (line && line[0] != '\0')
			status = sh_execute(line);

		/* test */
		if ((!interactive && line[0] == '\0' && end_of_file == EOF)
			|| (status < 0))
		{/* Once end of file is reached */

			/* Clean up */
			if (line)
				free(line);

			break;
		}

		/* Clean up */
		if (line)
			free(line);
		fflush(STDIN_FILENO);
		errno = 0;
	}
}
