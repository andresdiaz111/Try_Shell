#include "library.h"

/**
 * built_env - search env command and print
 * @commands: array of strings with the commands
 * @num_commands: number of commands in the array
 *
 * Return: none
 */
void built_env(char ***commands, int num_commands)
{
	int cmp;
	size_t index = 0;
	char *aux_commands = NULL;

	if (!(*commands) || num_commands != 2)
		return;
	aux_commands = (*commands)[0];
	cmp = _strcmp(aux_commands, "env");
	if (cmp == 0)
	{
		while (environ[index])
		{
			_print1(STDOUT_FILENO, environ[index++]);
			_print1(STDOUT_FILENO, "\n");
		}
		free(*commands);
		*commands = NULL; /* NO dangling pointer */
	}
}

/**
 * built_exit - search exit and set exit status
 * @commands: array of strings with the commands
 * @num_commands: number of commands in the array
 * @exit_status: exit status
 *
 * Return: none
 */
void built_exit(char ***commands, int num_commands, ssize_t *exit_status)
{
	int cmp;
	char *aux_commands = NULL;

	if (!(*commands) || num_commands != 2)
		return;
	aux_commands = (*commands)[0];
	cmp = _strcmp(aux_commands, "exit");
	if (cmp == 0)
	{
		*exit_status = -1;
		free(*commands);
		*commands = NULL; /* NO dangling pointer */
	}
}
