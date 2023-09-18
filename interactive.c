#include "main.h"
/**
 * interactive_mode - command line intepreter
 *
 * Return: void
 */
void interactive_mode(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		write(1, "Xshell$ ", 10);
		line = readline();
		args = process_line(line);
		status = execute_args(args);

		/** free memory **/
		free(line);
		free(args);

		/** exit with status **/
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
