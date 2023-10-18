#include "shell.h"
/**
 * exit_me - function to exit
 * @status: passed status
 * Return: status code
 */
int exit_me(int *status)
{
	int status_code = 0;

	if (WIFEXITED(*status))
	{
		*status = WEXITSTATUS(*status);
		if (status_code == 0)
		{
			return (0);
		}
		else
		{
			return (status_code);
		}
	}
	return (0);
}
