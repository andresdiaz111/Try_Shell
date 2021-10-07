#include "library.h"

/**
 * init_path - copy the all directories of the path
 * @path: path to copy
 *
 * Return: a pointer to the init linked list
 */
list_t *init_path(char **path)
{
	list_t *dirs = NULL;
	char *aux;

	aux = _getenv("PATH");
	if (*aux == '\0')
		return (NULL);
	dirs = get_path_dirs(aux, path);
	return (dirs);
}

/**
 * get_path_dirs - tokenize a list of directories into a linked list
 * @aux: env PATH
 * @path: path to copy
 *
 * Return: a pointer to the head to linked list
 */
list_t *get_path_dirs(char *aux, char **path)
{
	list_t *head = NULL;
	list_t *path_N;
	const char *DELIM = ":\0";
	char *token = NULL;

	if (!(aux))
		return (NULL);
	*path = _strdup(aux);
	path_N = malloc(sizeof(list_t));
	if (!(path_N))
		return (NULL);
	path_N->next = head;
	token = strtok(*path, DELIM);
	path_N->dir = token;
	head = path_N;
	while (token)
	{
		token = strtok(NULL, DELIM);
		if (!(token))
			break;
		path_N = malloc(sizeof(list_t));
		if (!(path_N))
			return (NULL);
		path_N->dir = token;
		path_N->next = head;
		head = path_N;
	}
	return (head);
}

/**
 * create_path - create the path to run the command
 * @commands: command to run
 * @path: path to create
 *
 * Return: pointer to the path for use the command
 */
char *create_path(char ***commands, list_t *path)
{
	char *aux_commands;
	char *cp_path = NULL;
	list_t *aux_dir;
	int size_commands;
	int size_path;
	struct stat aux;

	if (!(*commands))
		return (NULL);
	aux_dir = path;
	if (!(aux_dir))
		return (NULL);
	aux_commands = *(commands)[0];
	size_commands = _strlen(aux_commands);
	while (aux_dir)
	{
		size_path = _strlen(aux_dir->dir);
		cp_path = (char *) malloc(size_path + size_commands + 2);
		if (!(cp_path))
			return (NULL);
		*cp_path = '\0';
		_strcat(cp_path, aux_dir->dir);
		_strcat(cp_path, "/");
		_strcat(cp_path, aux_commands);
		if (stat(cp_path, &aux) == 0)/*INVALID PATH OR FILENAME*/
			break;
		free(cp_path);
		cp_path = NULL;/* NO DANGLING POINTER :D*/
		aux_dir = aux_dir->next;
	}
	return (cp_path);
}

/**
 * check_path - Check if the path exist and permissions to use
 * @commands: array of the string (commands)
 * @total_path: Path to check
 * @av: name of the shell .exe
 * @history: count of the last commands
 * @exit_status: save the status of error
 *
 * Return: none
 */
void check_path(char ***commands, char **total_path,
		char **av, int *history, int *exit_status)
{
	char *error_msg = NULL;
	char *aux_commands = NULL;
	char *buffer;
	char *buffer1;

	if ((*total_path) || !(*commands))
		return;
	aux_commands = *(commands)[0];
	/*F_OK - file exist,X_OK permission*/
	if (access(aux_commands, F_OK | X_OK) == 0)
		*total_path = _strdup(aux_commands);
	else
	{
		if (access(aux_commands, X_OK) != 0)
		{
			error_msg = "Permission denied\n";
			*exit_status = 126;
			buffer = _itoa(*history);
			create_error(av[0], aux_commands, error_msg, buffer);
		}
		else if (access(aux_commands, F_OK) != 0)
		{
			error_msg = "path not found\n";
			*exit_status = 127;
			buffer1 = _itoa(*history);
			create_error(av[0], aux_commands, error_msg, buffer1);
		}
	}
}

/**
 * check_directories - Check if the directorie exist
 *	and file permissions to use
 * @commands: array of the string (commands)
 * @total_path: Path to check
 * @av: name of the shell .exe
 * @history: count of the last commands
 * @exit_status: save the status of error
 *
 * Return: none
 */

void check_directories(char ***commands, char **total_path,
		char **av, int *history, int *exit_status)
{
	char *aux_commands = NULL;
	char *buffer;
	char *error_msg = NULL;
	struct stat aux;

	if (*commands == NULL)
		return;

	aux_commands = *(commands)[0];

	if (stat(aux_commands, &aux) == 0)
	{
		if ((aux.st_mode & S_IFMT) == S_IFDIR)
		{
			buffer = _itoa(*history);
			*exit_status = 126;
			error_msg = "Permission denied\n";
			create_error(av[0], aux_commands, error_msg, buffer);

			if (*total_path != NULL)
			{
				free(*total_path);
				*total_path = NULL;
			}
		}
	}
}
