#include "shell_library.h"

/**
 * compare - compares two strings
 * @varname: first character
 * @dirname: second character
 *
 * Return: 1
 */

int compare(char *varname, char *dirname)
{
	int r;

	for (r = 0; dirname[r] != '\0'; r++)
	{
		if (dirname[r] != varname[r])
			return (0);
	}
	return (1);
}

/**
 * length - checks the equal sign
 * @str: character
 * Return: str
 */

char *length(char *s)
{
	int j;

	for (j = 0; s[j] != '='; j++)
		;
	return (s + j + 1);
}

/**
 * _getenv - function that gets the path in the environ
 * @environ: global variable
 * @dirname: is a char
 * Return: final or null
 */

char *_getenv(char **environ, char *dirname)
{
	int u, v;
	char *varname, *final;

	for (v = 0; environ[v]; v++)
	{
		varname = malloc(1024);

		for (u = 0; environ[v][u] != '='; u++)
			varname[u] = environ[v][u];

		if (compare(varname, dirname))
		{
			final = length(environ[v]);
			free(varname);
			return (final);

		}
		free(varname);
	}
	return (NULL);
}