#include "main.h"
/**
 * execmd - executes a shell command using execve
 * @argv: command list
 *
 * Return: 1 on success
 */

int execmd(char *program_name, char **argv)
{
	pid_t pid;
	int status;
	char *dir, *path;
	char full_path[1024];

	/** does argv[0] exist : iscommand() */
	if (strchr(argv[0], '/') == NULL)
	{
		path = iscommand(argv[0]);
		if (!path)
		{
			fprintf(stderr, "%s: No such file or directory\n", program_name);
			exit(EXIT_FAILURE);
		}
		else
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", path, argv[0]);
			dir = full_path;
		}
	}
	else
		dir = argv[0];

	pid = fork();
	if (pid == 0)
	{
		/* child process*/
		if (execve(dir, argv, NULL) == -1)
		{
			perror(program_name);
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

/**
 * iscommand - check if command exist
 * @cmd:  command to check
 *
 * Return: return the full directory of command
 */
char *iscommand(char *cmd)
{
	char *path = _getenv("PATH");
	char *path_token = strtok(path, ":");
	char full_path[1024];

	while (path_token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", path_token, cmd);

		/** check if the command exist in this directory **/
		if (access(full_path, X_OK) == 0)
		{
			return (strdup(path_token));
		}
		path_token = strtok(NULL, ":");
	}
	return (NULL);
}
