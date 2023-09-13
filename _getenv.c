#include "_getenv.h"

/**
 * _getenv - get an environmnet variable
 * @name: name of variable
 *
 * Return: a pointer to the value of the variable in the environment
 * else NULL if not found
 */
char *_getenv(const char *name)
{
	unsigned int i = 0;

	if (name == NULL)
	{
		return (NULL);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0)
		{
			/* add 1 for the '=' sign */
			return (environ[i] + strlen(name) + 1);
		}
	}

	return (NULL);
}
