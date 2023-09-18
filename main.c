#include "main.h"
/**
 * main - start shell and check for mode
 *
 * Return: int 0 on success
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char *program_name = argv[0];

	/* check file descriptor */
	if (isatty(STDIN_FILENO == 1))
	{
		interactive_mode(program_name);
	}
	else
	{
		non_interactive_mode(program_name);
	}
	return (0);

}
