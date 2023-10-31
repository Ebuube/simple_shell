#include "shell.h"

/**
 * main - Entry of simple shell program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(UNUSED int argc, char *argv[])
{
	/* START OF PROGRAM */
	/* Set signal handler */
	if (signal(SIGINT, sig_handler) == SIG_ERR)
	{
		fprintf(stderr, "An error occured while setting signal handler");
		exit(EXIT_FAILURE);
	}
	ERR_PROMPT = argv[0];
	SHELL.interactive = isatty(STDIN_FILENO);
	SHELL.ERR_NO_BUILTIN = -14;
	SHELL.BUILTIN_SUCCESS = 14;
	SHELL.END_SUCCESS = 134;
	SHELL.END_FAILURE = 123;
	SHELL.END_SHELL = 145;
	SHELL.FORK_EXEC_FAILURE = -412;
	SHELL.LAST_EXIT_STATUS = 0;
	SHELL.CMD_NOT_FOUND = 127;

	sh_loop();

	/* END OF PROGRAM */
	return (0);
}
