#include "library.h"

/**
 * _getenv - Function for get enviroment.
 * @name: This is the C string containing
 * the name of the requested variable.
 * Return: a pointer to the value in the
 * environment, or NULL if there is no match.
 */

char *_getenv(const char *name)
{
	unsigned int x;
	unsigned int j = 0;
	char *value;
	int aux;

	while (name[j] != '\0')
	{
		j++;
	}

	for (x = 0; environ[x] != NULL; x++)
	{
		aux = _strncmp(environ[x], name, j);
		if (aux == 0)
			break;
	}
	value = environ[x] + (j + 1);
	if (value == NULL)
	{
		return (NULL);
	}
	return (value);
}
