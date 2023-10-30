#include "shell.h"

/**
 * sig_handler - handle what happens when a signal is received
 * @signo: the number of a signal
 *
 * Return: nothing
 */
void sig_handler(UNUSED int signo)
{
#ifdef TEST_CODE
	printf("SIG NUMBER -> %d\nTerminating\n", signo);
#endif
	putchar('\n');
	exit(EXIT_SUCCESS);
}
