#include "main.h"
/**
 * non_interactive_mode - command line intepreter
 * @program_name: program name
 * Return: void
 */
void non_interactive_mode(char *program_name)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = readstream();
		args = process_line(line);
		status = execute_args(program_name, args);

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
