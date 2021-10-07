#include "library.h"
/**
 * separate_commands - separated the commands with the delimiter
 * @commands: commands
 * @buffer: array of strings
 * @bytes: number of commands
 *
 * Return: none
 */
void separate_commands(char ***commands, char **buffer, int bytes)
{
	int index;
	const char *DELIM = " \n\t";
	char *cp_commands = NULL;

	*commands = malloc(bytes);
	cp_commands = strtok(*buffer, DELIM);
	for (index = 0 ; cp_commands ; index++)
	{
		(*commands)[index] = cp_commands;
		cp_commands = strtok(NULL, DELIM);
	}
	(*commands)[index] = cp_commands;
}
/**
 * commands_lenght - get the number of words separated by a pattern
 * @bytes: bytes read in the getline
 * @buffer: buffer to read
 *
 * Return: number of commands passed
 */
int commands_lenght(ssize_t bytes, char **buffer)
{
	const char *DELIM = " \n\t";
	char *aux_commands = NULL;
	char *cp_buffer = NULL;
	size_t index;

	cp_buffer = (char *) malloc(bytes);
	_strcpy(cp_buffer, *buffer);
	aux_commands = strtok(cp_buffer, DELIM);
	for (index = 0 ; aux_commands ; index++)
		aux_commands = strtok(NULL, DELIM);
	index++;
	free(cp_buffer);
	return (index);
}
/**
 * put_nullc - put null in a new line
 * @buffer: dest to change
 *
 * Return: none
 */
void put_nullc(char **buffer)
{
	size_t index = 0;

	while ((*buffer)[index] != '\0')
		index++;
	(*buffer)[index - 1] = '\0';
}
/**
 * get_commands - get the commands to the STDINPUT
 * @buffer: string to store the STDINPUT
 * @commands: commands to tokenize
 *
 * Return: byter reads in STDINPUT
 */
ssize_t get_commands(char **buffer, char ***commands)
{
	int aux;
	int index;
	ssize_t bytes;
	size_t buff_size = 0;

	*commands = NULL;
	bytes = getline(buffer, &buff_size, stdin);
	if (bytes > 0)
	{
		index = 0;
		while ((*buffer)[index] == ' ' || (*buffer)[index] == '\t')
		{
			if ((*buffer)[1 + index] == '\n')
				return (bytes);
			index++;
		}
	}
	if (bytes > 0 && **buffer != '\n')
	{
		put_nullc(buffer);
		aux = commands_lenght(bytes, buffer);
		separate_commands(commands, buffer, aux);
		built_env(commands, aux);
		built_exit(commands, aux, &bytes);
	}
	return (bytes);
}
