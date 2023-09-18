#include "main.h"
/**
 * execmd - executes a shell command using execve
 * @argv: command list
 *
 * Return: Void
 */

int execmd(char **argv)
{
	pid_t pid;
	int status;
	char *cmd = NULL;
	/*char *args[] = {"/bin/ls", "-l", NULL}; */

	pid = fork();
	if (pid == 0)
	{
		/* child process*/
		cmd = argv[0];
		/** execute command */
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("error in creating new process: child_process");
		}
	} else if (pid < 0)
	{
		/*Error forking*/
		perror("error in nw_process: forking");
	} else
	{
		/* Parent Process*/
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);

}
