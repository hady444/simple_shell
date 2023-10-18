#include "shell.h"
/**
 * tokenization - tokenize each word in command string
 * @args: pointer to array to save each token in
 * @argv: arguments in main
 * @command: commands passed
 * @status: status code
 * Return: 1 if there exit command
 */
int tokenization(char *args[], char *argv[], char **command, int *status)
{
	const char *delim = " \t\n\"";
	char *token;
	int i;

	token = strtok(*command, delim);
	if (!token)
		free(*command), free(token), exit(0);
	i = 0;
	while (token)
	{
		if (handel_comments(&token) == 1)
			args[i] = token, token = strtok(NULL, delim), i++;
		else
			break;
	}
	if (!token)
		free(token);
	args[i] = NULL;
	if (!args[0])
		return (1);
	if (str_cmp(args[0], "exit") == 0)
	{
		exit_me(status);
		return (1);
	}
	else if (str_cmp(args[0], "env") == 0)
	{
		_printenv();
		return (0);
	}
	handel_path(args, argv, command, status);
	return (0);
}
