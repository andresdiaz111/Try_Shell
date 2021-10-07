#include "library.h"

/**
 * create_error - Print the error message in the STDERR
 * @av: shell name .exe
 * @aux_commands: command with the error
 * @error_msg: error mesage print in the STDERR
 * @history: history count in char
 *
 * Return: none
 */
void create_error(char *av, char *aux_commands, char *error_msg, char *history)
{
	char *space = ": ";

	_print1(STDERR_FILENO, av);
	_print1(STDERR_FILENO, space);
	_print1(STDERR_FILENO, history);
	_print1(STDERR_FILENO, space);
	_print1(STDERR_FILENO, aux_commands);
	_print1(STDERR_FILENO, space);
	_print1(STDERR_FILENO, error_msg);
}
