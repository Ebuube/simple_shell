#include "shell.h"

/**
 * sh_execute - execute the passed program
 * @cmd: the command to execute
 *
 * Return: 0 on success, else -1 on failure.
 */
pid_t sh_execute(char *cmd)
{
	char **args = NULL;
	pid_t proc_id = 0, status = 0;

	args = get_args(cmd);
	if (cmd == NULL || args == NULL)
	{
		return (-1);
	}

	proc_id = fork();
	if (proc_id == -1)
	{/* Error forking this process */
		return (-1);
	}
	if (proc_id == 0)
	{/* Child process */
		status = execve(args[0], args, environ);
		if (args)
		{
			free(args);
			args = NULL;
		}
		if (cmd)
			free_str_safe(&cmd);
		if (status < 0)
		{/* Error executing command */
			perror(ERR_PROMPT);
			exit(EXIT_FAILURE);
		}
	}
	if (proc_id > 0)	/* Parent process */
		wait(NULL);
	if (args)
		free(args);
	return (status);
}

/**
 * get_args - create an argument vector from a string of input
 * @cmd: string value of command
 *
 * Return: an argument vector of instructions, else NULL
 */
char **get_args(char *cmd)
{
	char **args = NULL;
	const char *DELIM = " \n";

	if (cmd == NULL)
	{
		return (NULL);
	}

	args = tokenize(cmd, DELIM);
	if (args == NULL)
	{
		return (NULL);
	}
	if (args[0] == NULL)
	{
		free(args);
		args = NULL;
		return (NULL);
	}

	return (args);
}
