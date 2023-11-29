#include "shell.h"

/**
 * sh_readline - reads a  line of input from the commandline
 *
 * Return: a pointer to the string of input or NULL on error
 */
char *sh_readline(void)
{
	char *line = NULL;
	ssize_t nread = 0;
	size_t size = 0;

	nread = getline(&line, &size, stdin);
	if (nread == -1)
	{/* END OF FILE */
		if (line)
			free_str_safe(&line);
		if (SHELL.interactive)
			putchar('\n');
		exit(EXIT_SUCCESS);
	}

	printf("sh_readline: raw line: '%s'\n", line);	/* test */
	if ((size_t)nread < size - 1)
	{
		size = (line[nread - 1] == '\n') ? nread : nread + 1;
		line = realloc(line, size);
		if (line == NULL)
		{
			exit(EXIT_FAILURE);
		}
		line[size - 1] = '\0';
	}

	printf("sh_readline: null term line: '%s'\n", line);	/* test */
	trim(&line);
	if (line == NULL)
	{
		return (NULL);
	}
	printf("sh_readline: trimmed line: '%s'\n", line);	/* test */

	return (line);
}
