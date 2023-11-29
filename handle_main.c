#include "main.h"

/**
 * func_handle_exit - handle the exit commande
 * @first_arg: the first command
 * @buffer: the main buffer
 * @argv: the array of arguments
 */

void func_handle_exit(char *first_arg, char *buffer, char **argv)
{
	int n_exit = 0;

	if (argv[1])
		n_exit = _atoi(argv[1]);

	free(first_arg), free(buffer), free(argv);
	exit(n_exit);
}


/**
 * _get_direct - get a directory based on the command provided
 * @cmd: command provided by the user
 * Return: a pointer to dir or NULL
 */

char *_get_direct(char *cmd)
{
	char *path;
	char *token;
	char *full_command;
	struct stat st;

	path = getenv("PATH");
	token = strtok(path, ":");

	if (stat(cmd, &st) == 0)
	{
		return (cmd);
	}
	else
	{
		while (token)
		{
			full_command = malloc(strlen(token) + strlen(cmd) + 2);

			strcpy(full_command, token);
			strcat(full_command, "/");
			strcat(full_command, cmd);
			if (stat(full_command, &st) == 0)
				return (full_command);

			free(full_command);
			token = strtok(NULL, ":");
		}
	}
	return (NULL);
}
