#include "main.h"

/**
 * envprint - gets env
 *
 * Description: something
 */

void envprint(void)
{
	int i;
	int len;

	for (i = 0; __environ[i] != NULL; i++)
	{
		len = _strlen(__environ[i]);
		write(1, __environ[i], len);
		write(1, "\n", 1);
	}
}
