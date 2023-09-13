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
	int i = 0;	/* test */

	args = tokenize(cmd);
	if (cmd == NULL || args == NULL)
	{
		return (-1);
	}
	if (args[0] == NULL)
	{/* no program to run */
		free(args);
		args = NULL;
		return (0);
	}
	for (i = 0; args[i]; i++)
		printf("args[%d] -> '%s'\n", i, args[i]);	/* test */

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

	if (proc_id > 0)
	{/* Parent process */
		wait(NULL);
	}

	if (args)
		free(args);

	return (status);
}
