#include "shell.h"

/**
 * sh_readline - reads a  line of input from the commandline
 *
 * Return: a pointer to the string of input or NULL on error
 */
char *sh_readline(char *eof)
{
	char *buffer = NULL;
	size_t mem_size = BUFSIZE, pos = 0;
	int c = 0;

	buffer = malloc(mem_size * sizeof(char));
	if (!buffer)
	{
		return (NULL);
	}

	while (1)
	{
		c = getchar();

		/* Handling end of file */
		(*eof) = (c == EOF) ? EOF : (*eof);
		if (c == EOF || c == '\n')
		{
			buffer[pos] = '\0';
			break;
		}
		else
			buffer[pos] = c;

		pos++;
		if (pos == mem_size && buffer[pos] != '\0')
		{/* Input longer than available memory */
			mem_size += BUFSIZE;
			buffer = realloc(buffer, mem_size * sizeof(char));
			if (!buffer)
			{
				return (NULL);
			}
		}
	}
	if (pos < mem_size - 1)
	{
		printf("\n-----------------------START OF FILE---------------------\n");	/* test */
		printf("str: -> '%s'\n", buffer);	/* test */
		printf("pos(%lu)\tmem_size(%lu)\n", pos, mem_size);	/* test */
		buffer = realloc(buffer, pos + 1);
		if (!buffer)
		{
			return (NULL);
		}
		mem_size = pos + 1;
		printf("pos(%lu)\t", pos);	/* test */
		printf("strlen(buffer) -> %lu\t", strlen(buffer));	/* test */

		printf("\n------------------------END OF FILE---------------------\n");	/* test */
		printf("Successfully freed memory\n");	/* test */
	}

	return (buffer);
}
