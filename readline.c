#include "main.h"
/**
 * readline - read the line process
 *
 * Return: strings read from the command line
*/
char *readline(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;

	nread = getline(&line, &n, stdin);
	/* check 4 function failure and “end of file”/Ctrl+D condition*/
	if (nread == -1)
	{
		if (feof(stdin))
		{
			/** we receive EOF */
			free(line);
			exit(EXIT_SUCCESS);
		} else
		{
			/** getline fails */
			free(line);
			perror("error while reading from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return line;
}
