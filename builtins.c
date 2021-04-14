#include "shell.h"

int check_builtins(char **command_array, char *buffer)
{
	char *builtins[] = { "exit", "env", "cd", NULL };
	int i = 0;

	while (builtins[i])
	{
		if (_strcmp(command_array[0], builtins[i]) == 0)
		{
			switch (i)
			{
				case 0:
					_getoutof(command_array, buffer);
				case 1:
				/*	_env_print(); */
					return (1);
				case 2:
					chdir(command_array[1]);
					return (1);
				default:
					break;

			}
		}
		i++;
	}
	return (0);
}