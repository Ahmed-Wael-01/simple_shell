#include "main.h"

/**
 * _getenv - gets env
 * @name: a var
 *
 * Description: something
 * Return: 0
 */

char *_getenv(const char *name)
{
	int i = 0, j = 0;
	int nlen = 0;
	int elen = 0;
	char **env = environ;

	while (name[i] != '\0')
		nlen++, i++;
	for (i = 0; env[i] != NULL; i++)
	{
		j = 0;
		elen = 0;
		while (env[i][j] != '=')
			elen++, j++;
		if (nlen != elen)
			continue;
		for (j = 0; j <= nlen; j++)
		{
			if (name[j] == '\0' && env[i][j] == '=')
				return (&env[i][j + 1]);
			if (env[i][j] != name[j])
				break;
		}
	}
	return (NULL);
}
