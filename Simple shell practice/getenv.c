#include "shell_library.h"

/**
 * length - function that checks the = character
 * @str: is a char
 * Return: str
 */

char *length(char *str)
{
	int i;

	for (i = 0; str[i] != '='; i++)
		;
	return (str + i + 1);
}


/**
 * _getenv - function that gets the path in the environ
 * @environ: global variable
 * @dirname: is a char
 * Return: final or null
 */

char *_getenv(char **environ, char *dirname)
{
	int k, j;
	char *varname, *final;

	for (j = 0; environ[j]; j++)
	{
		varname = malloc(1024);

		for (k = 0; environ[j][k] != '='; k++)
			varname[k] = environ[j][k];

		if (_strcmp(varname, dirname))
		{
			final = length(environ[j]);
			free(varname);
			return (final);

		}
		free(varname);
	}
	return (NULL);
}