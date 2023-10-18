#include "shell.h"
/**
 * loop_shell - our shell
 * @path: address of environment path
 * @argv: arguments passef in main
 *
 */
void loop_shell(char **path, char **argv)
{
	const char *delim = " \t\n\"";
	char *command, *token, *args[1024];
	size_t cmd_len = 0;
	ssize_t cmd_size;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* interactive mode */
			write(STDOUT_FILENO, "$ ", 2);
		command = malloc(sizeof(char) * 1024);
		if (command != NULL)
			free(command), command = NULL;
		cmd_size = getline(&command, &cmd_len, stdin);
		if (cmd_size == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(*path), free(command), exit(0);
		}
		if (str_cmp(command, "\n") == 0)
		{
			free(command);
			continue;
		}
		command[cmd_size - 1] = '\0';
		token = strtok(command, delim);
		if (!token)
			free(command), free(token), free(*path), exit(0);
		i = 0;
		while (token)
			args[i] = token, token = strtok(NULL, delim), i++;
		free(token);
		args[i] = NULL;
		if (str_cmp(args[0], "exit") == 0)
			free(path), exit(0);
		handel_path(args, path, argv, &command), free(command);
	}
}
/**
 * handel_path - handeling path of environment
 * @args: arguments tokinized
 * @path: address of environment path
 * @argv: arguments passef in main
 * @command: firstly made command to be freed
 */
void handel_path(char *args[], char **path, char **argv, char **command)
{
	struct stat st;
	pid_t p;
	int status;

	if (stat(args[0], &st) == 0)
	{
		p = fork();
		if (p == 0)
		{
			execve(args[0], args, environ);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else if (p > 0)
			wait(&status);
		else
		{
			perror("fork"), exit(EXIT_FAILURE);
		}
	}
	else
	{
		with_path(args, path, argv, command);
	}
}
/**
 * with_path - handeling path of environment
 * @args: arguments tokinized
 * @path: address of environment path
 * @argv: arguments passef in main
 * @command: firstly made command to be freed
 */
void with_path(char *args[], char **path, char **argv, char **command)
{
	char *cmd_1st, *number;
	struct stat st;
	int status;
	pid_t p;
	static int err_num = 1;

	cmd_1st = NULL;
	if ((*path) != NULL)
		cmd_1st = get_command(*path, args[0], &st);
	if (cmd_1st != NULL)
	{
		p = fork();
		if (p == 0)
		{
			execve(cmd_1st, args, environ);
			perror(argv[0]);
			free(cmd_1st);
			exit(EXIT_FAILURE);
		}
		else if (p > 0)
		{
			wait(&status);
			free(cmd_1st);
		}
		else
		{
			perror("fork"), free(cmd_1st), exit(EXIT_FAILURE);
		}
	}
	else
	{
		number = intToString(err_num);
		print_error(argv[0], number, args[0]);
		err_num++, free(number), free(cmd_1st);
		if (!isatty(STDIN_FILENO))
		{
			free(*path), free(*command), exit(127);
		}
	}
}
/**
 * print_error - function made to identify error to stderr
 * @arg1: name of run file
 * @number: the order of command error in shell
 * @arg3: passed command
 */
void print_error(char *arg1, char *number, char *arg3)
{
	write(2, arg1, str_len(arg1));
	write(2, ": ", 2);
	write(2, number, str_len(number));
	write(2, ": ", 2);
	write(2, arg3, str_len(arg3));
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}
/**
 * get_command - adjusting command with env path
 * @path: environment path
 * @cmd: passed command
 * @st: stat struct
 * Return: full command with path
 */
char *get_command(char *path, char *cmd, struct stat *st)
{
	char *token;
	char *path_copy = malloc(str_len(path) + 1);
	char *command_full = NULL;

	str_cpy(path_copy, path);
	token = strtok(path_copy, ":");
	while (token)
	{
		command_full = malloc(str_len(token) + str_len(cmd) + 2);
		str_cpy(command_full, token);
		str_cat(command_full, "/");
		str_cat(command_full, cmd);
		if (stat(command_full, st) == 0)
		{
			free(path_copy);
			return (command_full);
		}
		free(command_full);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}