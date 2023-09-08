#include "shell.h"

/**
 * sh_execute - execute the passed program
 * @cmd: the command to execute
 *
 * Return: 0 on success, else -1 on failure.
 */
pid_t sh_execute(char *cmd)
{
	char *args[2] = {NULL, NULL};
	pid_t proc_id = 0, status = 0;

	if (cmd == NULL)
	{
		return (0);
	}
	args[0] = cmd;

	proc_id = fork();
	if (proc_id == -1)
	{/* Error forking this process */
		return (-1);
	}

	if (proc_id == 0)
	{/* Child process */
		status = execve(args[0], args, environ);
		if (status < 0)
		{/* Error executing command */
			perror(ERR_PROMPT);
			return (-1);
		}
	}

	if (proc_id > 0)
	{/* Parent process */
		wait(NULL);
	}

	return (status);
}
