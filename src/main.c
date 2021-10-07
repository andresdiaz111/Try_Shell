#include "library.h"

/**
 * execute - execute the loop and get the buffer in stdin
 * @av: commands array
 * Return: exit status
 */
int execute(char **av)
{
	list_t *path = NULL;
	char *prompt = "$ ";
	char **commands = NULL;
	char *buffer = NULL;
	char *cp_path = NULL;
	char *total_path = NULL;
	ssize_t bytes_c = 1;
	int exit_status;
	int flag = 1;
	int history = 1;

	path = init_path(&cp_path);
	if (isatty(STDIN_FILENO) == 0)
		flag = 0;
	while (1)
	{
		exit_status = 0;
		if (flag == 1)
			write(STDOUT_FILENO, prompt, 3);
		fflush(stdout);
		bytes_c = get_commands(&buffer, &commands);
		if (bytes_c == -1)
			break; /* BUILT_IN EXIT */
		total_path = create_path(&commands, path);
		check_path(&commands, &total_path, av, &history, &exit_status);
		check_directories(&commands, &total_path, av, &history, &exit_status);
		run(&buffer, &commands, total_path, &exit_status);
		history++;
	}
	free_path(path);
	free(buffer);
	free(cp_path);
	return (exit_status);
}
/**
 * free_path - free the all member in the linked list
 * @path: a first element of the data structure
 *
 * Return: none
 */
void free_path(list_t *path)
{
	list_t *aux;

	while (path)
	{
		aux = path;
		path = path->next;
		free(aux);
	}
	free(path);
}
/**
 * run - run the command
 * @buffer: string readed with getline
 * @commands: actions to perform
 * @total_path: path
 * @exit_status: status terminated program
 *
 * Return: return a number to termiante the program -7 fail, 1 exit
 */
int run(char **buffer, char ***commands, char *total_path, int *exit_status)
{
	pid_t child;
	pid_t wstatus;

	if (!(*commands))
		return (-7);
	if (!(total_path))
	{
		free(*commands);
		return (-7);
	}
	child = fork();
	if (child == 0)
	{
		execve(total_path, *commands, environ);
		if (errno == EACCES)
		{
			free(*buffer);
			free(*commands);
			exit(126);
		}
	}
	else
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
			*exit_status = WEXITSTATUS(wstatus);
	}
	free(total_path);
	free(*commands);
	return (0);
}
/**
 * new_Prompt - Print a new prompt with Ctrl-c
 * @sign: signal
 */
void new_Prompt(int  sign)
{
	(void)sign;
	write(STDOUT_FILENO, "\n$ ", 4);
}
/**
 * main - run a simple shell interpreter
 * @ac: number of arguments supplied to the programa
 * @av: array pointer to the arguments
 *
 * Return: value of the last command
 */
int main(int  ac, char **av)
{
	int last_value;

	(void)ac;
	signal(SIGINT, new_Prompt);
	last_value = execute(av);
	return (last_value);
}
