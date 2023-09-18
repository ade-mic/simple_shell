#include "main.h"
/**
* process_line - process what is typed in command line
* @lineptr: a strings of character read from user
* Return: lineptr_cpy a copy of the line strings
*/

char **process_line(char *lineptr)
{
	char *token, **tokens;
	const char *delim = " \t\r\n\a";
	int bufsize = 1024;
	int position = 0;

/** allocate space for array of words */
	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		fprintf(stderr, "memory allocation error in process_line: tokens\n");
		exit(EXIT_FAILURE);
	}

	/** split line into array of words using strtok*/
	/* calculate number of tokens*/
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		/** if comment **/
		if (token[0] == '#')
		{
			break;
		}
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, (bufsize * sizeof(char *)));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
