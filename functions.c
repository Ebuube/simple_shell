#include "main.h"

/**
 * hsh_loop - loops through to emulate a UNIX Commandline Interpreter
 * @argc: argument count
 * @argv: argument vector from main() function.
 * @envp: points to an array of environmental variables
 *
 * Return: 0 on success
 */
void hsh_loop(UNUSED int argc, UNUSED char *argv[], UNUSED char *const envp[])
{
	char *line = 0;
	/* args: to be modified when processing arguments */
	UNUSED char *args[2] = {NULL, NULL};
	UNUSED pid_t status = 0;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (getpid() > 0 && interactive)
		{
			/* for parent process only */
			printf("($) ");
		}

		line = hsh_readline();
		args[0] = line;
		status = hsh_execute(argc, line, args, envp);
		free(line);
		/* free(args) - when processing arguments */

		fflush(STDIN_FILENO);
		errno = 0;	/* reinitialise error number */
		if (!interactive)
		{
			/* non-interactive mode */
			break;
		}
	}
}

/**
 * hsh_execute - executes the passed function
 * @argc: argument count
 * @command: the command to execute
 * @args: arguments to the to command
 * @envp: points to an array of environmental variables
 *
 * Return: 0 on succcess
 */
pid_t hsh_execute(UNUSED int argc, UNUSED const char *command,
		UNUSED char *const *args, UNUSED char *const envp[])
{
	pid_t f_pid = 0, status = 0;

	f_pid = fork();

	if (f_pid == -1)
	{
		/* error forking this process */
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	if (f_pid == 0)
	{
		/* child process */
		status = execve(command, args, envp);
		if (status < 0)
			perror("hsh");	/* error executing the command */
		exit(EXIT_FAILURE);
	}
	if (f_pid > 0)
	{
		/* parent process */
		wait(NULL);
	}

	return (status);
}

/**
 * hsh_readline - reads a line of inputs from the commandline
 *
 * Return: pointer to the string of input
 */
char *hsh_readline(void)
{
	char *buffer = 0;
	size_t memlen = BUFSIZE, position = 0;
	int c = 0;

	buffer = malloc(memlen * sizeof(char));
	if (!buffer)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			break;
		}
else
			buffer[position] = c;
		position++;

		if (position == memlen)
		{
			/* if input is longer than get more memory */
			memlen += BUFSIZE;
			buffer = realloc(buffer, memlen * sizeof(char));
			if (!buffer)
			{
				perror("hsh");
				exit(EXIT_FAILURE);
			}
		}
	}

	return (buffer);
}
