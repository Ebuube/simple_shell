#include "shell.h"
#include "_getenv.h"

/**
 * _cd_btn - change curent working directory
 * @args: argument vector
 *
 * Description: if no arguments, works like `cd $HOME`
 * If `cd -`, it changes to previous working directory
 * pwd is updated
 */
pid_t _cd_btn(UNUSED const char **args)
{
	char *tmp = NULL;
	const int MAX_ARGS = 2;
	int i = 0;

	printf("_cd_btn: Entry\n");	/* test */
	if (args == NULL || args[0] == NULL)
	{
		return (SHELL.BUILTIN_FAILURE);
	}
	for (i = 0; args[i] != NULL; i++)
		printf("args[%d]: %s\n", i, args[i]);	/* test */

	printf("i -> %d\n", i);	/* test */
	if (i > MAX_ARGS)
	{
		fprintf(stderr, "cd: too many arguments\n");
		return (SHELL.BUILTIN_FAILURE);
	}
	if (i == 1)
	{
		tmp = _getenv("HOME");
		if (!tmp)
			return (SHELL.BUILTIN_FAILURE);
		if (chdir(tmp) != 0)
		{
			fprintf(stderr, "Could not access directory\n");
			return (SHELL.BUILTIN_FAILURE);
		}
	}

	printf("_cd_btn: Exit\n");	/* test */
	return (SHELL.BUILTIN_SUCCESS);
}
