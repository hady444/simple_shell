#include "shell.h"
/**
 * main - main func
 * @argc: number of inputs
 * @argv: inputs
 * Return: return 0 if success
 */
int main(__attribute__ ((unused)) int argc, char **argv)
{
	int status = 0;

	loop_shell(argv, &status);
	return (status);
}
