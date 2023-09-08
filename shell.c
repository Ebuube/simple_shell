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
	ERR_PROMPT = argv[0];

	sh_loop();

	/* END OF PROGRAM */
	return (0);
}
