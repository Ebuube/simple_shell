#include "main.h"

/**
 * main - Entry of simple shell program
 * @argc: argument count
 * @argv: argument vector
 * @envp: pointer to a set of enviromental variables
 *
 * Return: 0 on success
 */
int main(UNUSED int argc, UNUSED char *argv[], UNUSED char *envp[])
{
	/* START OF PROGRAM */

	hsh_loop(argc, argv, envp);

	/* END OF PROGRAM */
	return (0);
}
