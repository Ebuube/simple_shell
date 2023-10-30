#include "shell.h"

/**
 * sh_loop - loops through to emulate a UNIX Commandline Interpreter
 *
 * Return: nothing
 */
pid_t sh_loop(void)
{
	char *line = NULL, **args = NULL;
	pid_t status = 0, ret_val = 0;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		line = NULL;
		if (interactive)
			printf(SHELL_PROMPT);

		line = sh_readline();
		if (line == NULL)
		{
			fflush(STDIN_FILENO);
			errno = 0;
			continue;
		}
		printf("sh_loop: line -> '%s'\n", line);	/* test */

		args = tokenize(line);
		if (args != NULL && args[0] != NULL)
		{
			status = sh_execute(args);
			/* free_array(args); */
			/* free(args); */
		}

		free(args);
		free_str_safe(&line);
		fflush(STDIN_FILENO);
		errno = 0;
		if (status < 0)
		{/* child process could not execute the command */
			ret_val = status;
			printf("sh_loop(child): qutting; status = %d\n",
				status);	/* test */
			exit(EXIT_FAILURE);
		}
	}

	return (ret_val);
}
