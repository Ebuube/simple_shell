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
 * Description: It attempts resolving the name of the program
 * to a file in PATH if possible, else
 * the program name is left the way it is.
 *
 * Return: an argument vector of instructions, else NULL
 */
char **get_args(char *cmd)
{
	char **args = NULL, *abs_path = NULL;
	const char *DELIM = " \n";

	if (cmd == NULL)
	{
		return (NULL);
	}

	printf("\n");	/* test */
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

	/* */
	if (args[0] != NULL && isalpha(args[0][0]))
	{
		printf("get_args: args[0][0] -> '%c'\n", args[0][0]);	/* test */
		abs_path = resolve_path(args[0]);
		if (abs_path != NULL)
		{
			free_str_safe(&args[0]);
			args[0] = abs_path;
			printf("get_args: abs_path -> %p\n", (void *)abs_path);	/* test */
		}
		else
			printf("get_args: abs_path -> '%s'\n", abs_path);	/* test */
	}
	/* */

	return (args);
}
