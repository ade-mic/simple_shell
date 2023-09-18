#include "main.h"

/**
 * _getenv - searches the environment list to find the environment variable name
 * @name: nsme of environment path
 *
 * Return: a pointer of to the corresponding string
 */
char *_getenv(const char *name)
{
	size_t n;
	int i = 0;

	if (name == NULL)
		return (NULL);

	n = _strlen(name);

	while(environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], n) == 0 && environ[i][n] == '=')
		{
			/** return the pointer of string **/
			return (&environ[i][n + 1]);
		}
		i++;
	}
	/** return NULL if path not found **/
	return (NULL);
}
