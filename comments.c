#include "shell.h"
/**
 * handel_comments - handel #
 * @args: command arguments
 */
int handel_comments(char **token)
{
	int i = 0;
	int len = str_len(*token);

	while (i < len)
	{
		if (*token[i] == '#')
		{
			return (0);
		}
		return (1);
		i++;
	}
	return (1);

}
