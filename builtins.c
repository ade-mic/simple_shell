#include "main.h"
/**
 * own_cd - a customiaed function of cd
 * @args: arguements
 *
 * Return:  1 on success;
 */
int own_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected arguement");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("filename");
		}
	}
	return (1);
}

/**
 * own_exit - exit the program
 * @args: arguements
 *
 * Return: 0 on success
 */
int own_exit(char **args)
{
	(void) args;
	return (0);
}

/**
 * own_env - print the environment
 *@args: arguements given to builtin function
 * Return: Always 0
 */
int own_env(char **args)
{
	unsigned int i = 0;

	(void) args;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (-1);
}
