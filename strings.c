#include "shell.h"
/**
 * str_len - get length of string
 * @s: string passed
 * Return: length
 */

int str_len(char *s)
{
	int j = 0;

	while (1)
	{
		if (*(s + j) == '\0')
			return (j);
		j++;
	}
	return (-1);
}
/**
 * str_cpy - copy string content to another string
 * @dest: destenation
 * @source: copied string
 * Return: string copy
 */
char *str_cpy(char *dest, char *source)
{
	int i = -1;

	do {
		i++;
		dest[i] = source[i];
	} while (source[i] != '\0');
	return (dest);
}
/**
 * str_cmp - meaure the difference between tow strings
 * @s1: string 1
 * @s2: string 2
 * Return: difference betwwen both
 */
int str_cmp(char *s1, char *s2)
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
/**
 * str_cat - add string to end of string
 * @dest: the string which will be added to
 * @src: concated string
 * Return: the whole char *
 */
char *str_cat(char *dest, char *src)
{
	int o = 0;
	int v = 0;

	while (dest[o] != '\0')
		o++;
	while (src[v] != '\0')
		dest[o + v] = src[v], v++;
	dest[o + v] = '\0';
	return (dest);
}
/**
 * str_dup - double struig
 * @str: string
 * Return: pointer
 */
char *str_dup(char *str)
{
	char *s = NULL;
	int t, r;

	if (str == NULL)
		return (NULL);

	t = 0;
	while (str[t] != '\0')
		t++;

	s = malloc(t * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);

	for (r = 0; r < t; r++)
		s[r] = str[r];

	s[r] = '\0';
	return (s);
}
