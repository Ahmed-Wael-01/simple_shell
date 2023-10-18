#include "main.h"

/**
 * shfree - free
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

void shfree(char **str)
{
	int i;

	for (i = 0; str[i] != NULL; i++)
		free(*(str + i));
	free(str);
}
