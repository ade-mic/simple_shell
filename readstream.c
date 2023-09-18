#include "main.h"
/**
 * readstream - read the line process
 *
 * Return: strings read from the input stream
*/
char *readstream(void)
{
	int bufsize = 1024;
	int byte, n = 0;
	char *line;

	line = malloc(sizeof(char) * bufsize);
	if (!line)
	{
		fprintf(stderr, "allocation error in readstream.c");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		/** read first character */
		byte = getchar();
		if (byte == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (byte == '\n')
		{
			line[n] = '\0';
			return (line);
		}
		else
		{
			line[n] = byte;
		}
		n++;
		if (n >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "error while reading from stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
