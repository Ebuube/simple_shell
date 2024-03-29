#include "shell.h"
#include "_getenv.h"

/**
 * _cd_btn - change curent working directory
 * @args: argument vector
 *
 * Description: if no arguments, works like `cd $HOME`
 * If `cd -`, it changes to previous working directory
 * pwd is updated
 *
 * Return: Success if all was processed fine, else FAILURE
 */
pid_t _cd_btn(UNUSED const char **args)
{
	const int MAX_ARGS = 2;
	int i = 0;

	if (args == NULL || args[0] == NULL)
	{
		return (SHELL.BUILTIN_FAILURE);
	}
	for (i = 0; args[i] != NULL; i++)
		;

	if (i > MAX_ARGS)
	{
		return (SHELL.BUILTIN_FAILURE);
	}
	if (i == 1)
	{
		if (_change_dir("HOME") == NULL)
			return (SHELL.BUILTIN_FAILURE);
	}
	else if (i == 2 && args[1])
	{
		if (_change_dir(args[1]) == NULL)
		{
			fprintf(stderr, "%s: 1: cd: can\'t cd to %s\n",
				ERR_PROMPT, args[1]);
			return (SHELL.BUILTIN_FAILURE);
		}
	}

	return (SHELL.BUILTIN_SUCCESS);
}

/**
 * _change_dir - change to a new working directory
 * @path: the path to change to
 *
 * Description: if path is 'HOME', it changes to home
 * if '-', it changes to previous working directory
 * else it changes to the specified directory
 * else it returns NULL
 * Return: path to directory chaged to
 */
char *_change_dir(const char *path)
{
	int i = 0;
	char *env_path_tb[][2] = {
		{"-", "OLDPWD"}, {"HOME", "HOME"},
		{NULL, NULL}
	};
	char *dir = NULL;
	char wdir[128];

	getcwd(wdir, 128);
	for (i = 0; env_path_tb[i][0]; i++)
	{/* find path if using signs */
		if (strcmp(path, env_path_tb[i][0]) == 0)
			dir = _getenv(env_path_tb[i][1]);
	}
	if (dir != NULL)
	{
		if (chdir(dir) != 0)
		{
			return (NULL);
		}
	}
	else if (dir == NULL && (strcmp(path, "-") != 0))
	{
		if (chdir(path) != 0)
		{
			return (NULL);
		}
	}

	setenv("OLDPWD", wdir, 1);
	getcwd(wdir, 128);
	setenv("PWD", wdir, 1);

	if (strcmp(path, "-") == 0)
		printf("%s\n", wdir);

	return ((char *)path);
}
