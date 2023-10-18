#include "shell.h"
/**
 * tokenization - tokenize each word in command string
 * @args: pointer to array to save each token in
 * @path: path of environment
 * @argv: arguments in main
 * @command: commands passed
 */
void tokenization(char *args[], char **path, char *argv[], char **command)
{
	const char *delim = " \t\n\"";
	char *token;
	int i;

	token = strtok(*command, delim);
	if (!token)
		free(*command), free(token), free(*path), exit(0);
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
		return;
	if (str_cmp(args[0], "exit") == 0)
		free(path), exit(0);
	handel_path(args, path, argv, command);
}
