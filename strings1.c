#include "shell.h"
/**
 * str_cmpc - compare both strings
 * @s1: string 1
 * @s2: const string
 * Return: 0 if equal
 */
int str_cmpc(char *s1, const char *s2)
{
	int i = 0, sum = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			sum += ((int) s1[i] - (int) s2[i]);
			break;
		}
		i++;
	}
	return (sum);
}
