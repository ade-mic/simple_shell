#include "main.h"
/**
 * main - start shell and check for mode
 *
 * Return: int 0 on success
 */

int main(void)
{

	/* check file descriptor */
	if (isatty(STDIN_FILENO == 1))
	{
		interactive_mode();
	}
	else
	{
		non_interactive_mode();
	}
	return (0);

}
