#include "main.h"

/**
 * pword - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

int pword(char *str)
{
	int counter = 0;
	int i = 0;

	if (str[i] != ':')
		counter++;
	i++;
	while (str[i] != '\0')
	{
		if (str[i] != ':' && str[i - 1] == ':')
			counter++;
		i++;
	}
	return (counter);
}

/**
 * plen - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

int plen(char *str)
{
	int len = 0;

	while (str[len] != '\0' && str[len] != ':')
		len++;
	return (len);
}

/**
 * psplice - gets env
 * @path: a var
 *
 * Description: something
 * Return: 0
 */

char **psplice(char *path)
{
	int i, j, wn = 0;
	char **vessel;

	if (path == NULL)
		return (NULL);
	i = pword(path);
	vessel = malloc(sizeof(path) * (i + 1));
	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i] != ':')
		{
			j = plen(&path[i]);
			*(vessel + wn) = malloc(sizeof(char) * (j + 1));
			for (j = 0; path[i] != '\0'
				&& path[i] != ':'; j++)
			{
				*(*(vessel + wn) + j) = path[i];
				i++;
			}
			*(*(vessel + wn) + j) = '\0';
			i--, wn++;
		}
	}
	*(vessel + wn) = NULL;
	return (vessel);
}
