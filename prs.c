#include "shell.h"
/**
 * intToString - convert int to str
 * @number: number to be converted
 * Return: number as string
 */
char *intToString(int number)
{
	int temp = number, isNegative, length, i, digit;
	char *str;
	int numDigits = 0;

	while (temp != 0)
	{
		temp /= 10;
		numDigits++;
	}

	if (number == 0)
	{
		str = (char *) malloc(2 * sizeof(char));
		if (str == NULL)
			exit(EXIT_FAILURE);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	isNegative = number < 0;
	length = numDigits + isNegative + 1;
	str = (char *) malloc(length * sizeof(char));
	if (str == NULL)
		exit(EXIT_FAILURE);

	i = length - 2;
	if (isNegative)
	{
		str[0] = '-';
		number = -number;
	}
	while (number != 0)
	{
		digit = number % 10;
		str[i] = '0' + digit;
		number /= 10;
		i--;
	}
	str[length - 1] = '\0';
	return (str);
}
