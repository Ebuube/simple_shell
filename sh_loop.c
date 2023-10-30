#include "shell.h"

/**
 * sh_loop - loops through to emulate a UNIX Commandline Interpreter
 *
 * Return: nothing
 */
pid_t sh_loop(void)
{
	char *line = NULL;
	pid_t status = 0;

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
		status = sh_run(line);

		free_str_safe(&line);
		fflush(STDIN_FILENO);
		errno = 0;
		if (status < 0)
		{/* child process could not execute the command */
			exit(EXIT_FAILURE);
		}
	}

	return (status);
}


/**
 * sh_run - prepare and execute a line
 * @line: line for execution
 *
 * Description: A new child is not called if command doesn't exist
 * Return: status of execution
 */
pid_t sh_run(char *line)
{
	char **args = NULL, **found = NULL;
	bool changed = false;
	pid_t status = 0;

	if (line == NULL)
	{
		return (0);
	}

	args = tokenize(line, NULL);
	if (args == NULL)
	{
		return (0);
	}

	found = add_path(args, &changed);
	if (args && args[0] != NULL && found != NULL)
		status = sh_execute(args);
	if (changed == true)
		free(args[0]);
	args[0] = "dummy";
	free(args);

	return (status);
}
