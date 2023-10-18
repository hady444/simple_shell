#include "shell.h"
/**
 * check_empty_env - check if env is empty
 *
 * Return: 1 if empty 0 if not
 */
int check_empty_env(void)
{
	int i = 0;

	while (environ[i])
		i++;
	return (i);
}
