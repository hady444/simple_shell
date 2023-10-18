#include "shell.h"
/**
 * main - main func
 * @argc: number of inputs
 * @argv: inputs
 * Return: return 0 if success
 */
int main(__attribute__ ((unused)) int argc, char **argv)
{
	loop_shell(argv);
	return (0);
}
