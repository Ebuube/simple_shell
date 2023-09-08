#include "shell.h"

/**
 * sig_handler - handle what happens when a signal is received
 * @signo: the number of a signal
 *
 * Return: nothing
 */
void sig_handler(int signo)
{
	printf("SIG NUMBER -> %d\nTerminating\n", signo);
	exit(EXIT_FAILURE);
}
