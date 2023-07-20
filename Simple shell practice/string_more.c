#include "shell_library.h"

/**
 * _strcpy - it copies a string
 * @dest: destination
 * @src: source
 *
 * Return: pointer to the destination
 */
char *_strcpy(char *destination, char *src)
{
	int i = 0;

	if (destination == src || src == 0)
		return (destination);
	while (src[i])
	{
		destination[i] = src[i];
		i++;
	}
	destination[i] = 0;
	return (destination);
}

/**
 * _strdup - it duplicates a string
 * @str: string to be duplicated 
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *stri)
{
	int length = 0;
	char *ret;

	if (stri == NULL)
		return (NULL);
	while (*stri++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--stri;
	return (ret);
}