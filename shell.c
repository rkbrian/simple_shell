#include "shell.h"
/**
 * main - main function of shell program
 * @argc: argument count
 * @argv: argument array
 * @env: environmental variable
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	char *buffer;
	char **command_array;
	size_t size;
	ssize_t line_size;
	(void)argv;
	(void)argc;
	(void)env;

	buffer = NULL;

	if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

	while ((line_size = getline(&buffer, &size, stdin)))
	{
		if (line_size == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		command_array = tokenize(buffer);
		execute(command_array, buffer);

		size = 0;
		buffer = NULL;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	free_token(command_array);
        exit(0);
}
