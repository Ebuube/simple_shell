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
	bool found_path = false;

	args = get_args(cmd, &found_path);
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
		if (cmd)
			free_str_safe(&cmd);
		status = execve(args[0], args, environ);
		if (found_path == true)
		{
			free(args[0]);
		}
		free(args);
		args = NULL;
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
 * @found_path: A pointer that is set to true if path was found
 *
 * Description: It attempts resolving the name of the program
 * to a file in PATH if possible, else
 * the program name is left the way it is.
 *
 * Return: an argument vector of instructions, else NULL
 */
char **get_args(char *cmd, bool *found_path)
{
	char **args = NULL, *abs_path = NULL;
	const char *DELIM = " \n";

	if (cmd == NULL || found_path == NULL)
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

	if (args[0] != NULL && isalpha(args[0][0]))
	{
		abs_path = resolve_path(args[0]);
		if (abs_path != NULL)
		{
			/* free_str_safe(&args[0]); */
			args[0] = abs_path;
			*found_path = true;
		}
	}

	return (args);
}
