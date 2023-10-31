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

	while (1)
	{
		line = NULL;
		errno = 0;
		if (SHELL.interactive)
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
		if (status == SHELL.FORK_EXEC_FAILURE)
		{/* child process could not execute the command */
			printf("sh_loop: child process could not execute command\n");	/* test */
			exit(EXIT_FAILURE);
		}
		if (errno == SHELL.END_SHELL)
		{
			exit(SHELL.LAST_EXIT_STATUS);
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
	{
		status = sh_execute(args);
		status = (status < 0) ? SHELL.FORK_EXEC_FAILURE : status;
	}
	if (args && args[0] != NULL && found == NULL)
	{
		errno = 0;
		status = run_builtin(args[0]);
	}
	if (errno == SHELL.ERR_NO_BUILTIN ||
		status == SHELL.ERR_NO_BUILTIN)
	{
		fprintf(stderr, "%s: 1: %s: not found\n",
			ERR_PROMPT, args[0]);
		SHELL.LAST_EXIT_STATUS = SHELL.CMD_NOT_FOUND;
	}
	if (changed == true)
		free(args[0]);
	args[0] = "dummy";
	free(args);

	return (status);
}

/**
 * run_builtin - executes a SHELL_BUILTIN
 * @builtin: name of builtin to execute
 *
 * Return: the return status of the builtin
 */
int run_builtin(const char *builtin)
{
	int i = 0;
	builtin_t funcs[] = {
		{"exit", _exit_shell}, {"env", _env_builtin}, {NULL, NULL}
	};

	if (builtin == NULL)
	{
		return (SHELL.ERR_NO_BUILTIN);
	}
	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (strcmp(builtin, funcs[i].opcode) == 0)
		{/* run and return exit status */
			return (funcs[i].f());
		}
	}

	return (SHELL.ERR_NO_BUILTIN);
}
