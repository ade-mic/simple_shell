#include "main.h"
/**
 * execmd - executes a shell command using execve
 * @argv: command list
 * @program_name: program_name
 * Return: 1 on success
 */

int execmd(char *program_name, char **argv)
{
	pid_t pid;
	int status;
	char *dir, *path;
	/*char full_path[1024];*/

	if (strchr(argv[0], '/') == NULL)
	{
		path = iscommand(argv[0]);
		if (!path)
		{
			perror(program_name);
			free(path);
			exit(EXIT_FAILURE);
		}
		dir = path;
	}
	else
		dir = argv[0];

	pid = fork();
	if (pid == 0)
	{      /* child process*/
		if (execve(dir, argv, NULL) == -1)
		{
			perror(program_name);
		}

	} else if (pid < 0)
	{	/*Error forking*/
		perror("error in nw_process: forking");
	} else
	{	/* Parent Process*/
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (strchr(argv[0], '/') == NULL)
		free(path);
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
	char *path, *path_token, *path_cpy, *full_path = NULL;

	path = _getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		return (NULL);
	}
	path_cpy = strdup(path);
	path_token = strtok(path_cpy, ":");

	while (path_token != NULL)
	{
		full_path = malloc(strlen(path_token) + strlen(cmd) + 2);
		if (!full_path)
		{
			perror("iscommand: memory allocation");
			free(path_cpy);
			return (NULL);
		}
		snprintf(full_path, strlen(path_token) + strlen(cmd) + 2,
			 "%s/%s", path_token, cmd);

		/** check if the command exist in this directory **/
		if (access(full_path, X_OK) == 0)
		{
			free(path_cpy);
			return (full_path);
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}
