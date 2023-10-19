#include "main.h"

/**
 * _atoi - does something
 * @s: a variable
 *
 * Description: a function
 * Return: 0
*/

int _atoi(char *s)
{
	int i;
	unsigned int num = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
			num = num * 10 + (s[i] - 48);
		else
			return (-1);
	}
	return (num);
}
