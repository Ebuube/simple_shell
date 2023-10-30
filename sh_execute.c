#include "shell.h"

/**
 * sh_execute - execute the passed program
 * @cmd: a list containing command and args as strings
 *
 * Return: 0 on success, else -1 on failure.
 */
pid_t sh_execute(char **cmd)
{
	int a = 0;	/* test */
	pid_t proc_id = 0, status = 0;

	/* test start*/
	for (a = 0; cmd && cmd[a] != NULL; a++)
	{
		printf("sh_execute: cmd[%d]: '%s'\n", a, cmd[a]);
	}
	/* test end */

	proc_id = fork();
	if (proc_id == -1)
	{/* Error forking this process */
		return (-1);
	}
	if (proc_id == 0)
	{/* Child process */
		status = execve(cmd[0], cmd, environ);
		/* free_array(cmd); */
		/* free(cmd); */
		if (status < 0)
		{/* Error executing command */
			printf("sh_execute(child): Execution failure; Status = %d\n",
				status);	/* test */
			perror(ERR_PROMPT);
			/* free(cmd); */
			/* exit(EXIT_FAILURE); */
			return (status);
		}
	}
	if (proc_id > 0)	/* Parent process */
	{
		printf("sh_execute(parent[%d]): started waiting\n",
			proc_id);	/* test */ 
		wait(NULL);
		printf("sh_execute(parent[%d]): stopped waiting\n",
			proc_id);	/* test */ 
		printf("sh_execute(parent[%d]): status = %d\n",
			proc_id, status);	/* test */ 
	}
	/*
	if (cmd)
		free(cmd);
	*/
	return (status);
}
