#include "main.h"
/**
 * execute_args - handling builtins or a process
 * @args: command and flags
 *
 * Returrn: 1 on success, 0 otherrwise
 */
int execute_args(char *program_name, char **args)
{
	char *builtinfunc_list[] = {"exit", "env", "cd"};

	int (*builtinfunc[])(char **) = {own_exit, own_env, own_cd};
	long unsigned int i;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (i = 0; i < (sizeof(builtinfunc_list) / sizeof(char *)); i++)
	{
		if (strcmp(args[0], builtinfunc_list[i]) == 0)
		{
			return ((*builtinfunc[i])(args));
		}
	}
	/** create process instead */
	return (execmd(program_name, args));
}
