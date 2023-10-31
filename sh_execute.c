#include "shell.h"

/**
 * sh_execute - execute the passed program
 * @cmd: a list containing command and args as strings
 *
 * Return: 0 on success, else -1 on failure.
 */
pid_t sh_execute(char **cmd)
{
	pid_t proc_id = 0, status = 0;
	int wstatus = 0;

	proc_id = fork();
	if (proc_id == -1)
	{/* Error forking this process */
		return (-1);
	}
	if (proc_id == 0)
	{/* Child process */
		status = execve(cmd[0], cmd, environ);
		if (status < 0)
		{/* Error executing command */
			perror(ERR_PROMPT);
			/* SHELL.LAST_EXIT_STATUS = status; */
			return (status);
		}
	}
	if (proc_id > 0)	/* Parent process */
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{/* if child exited normally, get its exit status */
			SHELL.LAST_EXIT_STATUS = WEXITSTATUS(wstatus);
		}
	}

	return (status);
}
