#include "shell.h"
/**
 * _printenv - print env on var=value pattern
 *
 */
void _printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], str_len(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
/**
 * _getenv - used  to obtain specific var's value
 * @com: the var
 * @var: address of var to be changed here
 */
void _getenv(const char *com, char **var)
{
	int i = 0, fr;
	char *key = NULL;
	char **envp_copy, *check_NULL;
	int j, envp_len;

	*var = NULL;
	for (envp_len = 0; environ[envp_len] != NULL; envp_len++)
	;
	envp_copy = malloc((envp_len + 1) * sizeof(char *));

	if (envp_copy == NULL)
		perror("malloc"), exit(EXIT_FAILURE);
	for (j = 0; j < envp_len; j++)
	{
		envp_copy[j] = str_dup(environ[j]);
		if (envp_copy[j] == NULL)
			perror("strdup"), exit(EXIT_FAILURE);
	}
	envp_copy[envp_len] = NULL;
	while (envp_copy[i])
	{
		key = strtok(envp_copy[i], "=");
		if (str_cmpc(key, com) == 0)
		{
			check_NULL = strtok(NULL, "\n");
			if (!check_NULL)
				break;
			*var = str_dup(check_NULL);
			for (fr = 0; envp_copy[fr] != NULL; fr++)
				free(envp_copy[fr]);
			free(envp_copy);
			return;
		}
		i++;
	}
	for (fr = 0; envp_copy[fr] != NULL; fr++)
		free(envp_copy[fr]);
	free(envp_copy), *var = NULL;
}
