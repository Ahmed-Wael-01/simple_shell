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

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
	}
}
