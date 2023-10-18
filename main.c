#include "shell.h"
/**
 * main - main func
 * @argc: number of inputs
 * @argv: inputs
 * Return: return 0 if success
 */
int main(__attribute__ ((unused)) int argc, char **argv)
{
	char *path;

	/*path = malloc(sizeof(char) * 1024);*/
	_getenv("PATH", &path);
	loop_shell(&path, argv);
	free(path);
	return (0);
}
