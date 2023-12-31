#include "main.h"

/**
 * execute - gets env
 * @cmd: a var
 * @av: a var
 *
 * Description: something
 * Return: 0
 */

int execute(char *cmd, char **av)
{
	struct stat st;
	int id = getpid();

	if (stat(cmd, &st) == 0)
	{
		fork();
		if (id == getppid())
		{
			execve(cmd, av, environ);
			exit(98);
		}
		wait(NULL);
		return (0);
	}
	return (1);
}

/**
 * path_search - gets env
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

int path_search(char **str)
{
	struct stat st;
	int i = 0, id;
	char **path;
	char cmd[100];

	if (str == NULL)
		return (1);
	else if (stat(str[i], &st) == 0)
	{
		id = fork();
		if (id == 0)
			execve(str[i], str, environ);
		wait(NULL);
		shfree(str);
		return (0);
	}
	else
	{
		path = psplice(_getenv("PATH"));
		while (path[i] != NULL)
		{
			_strcpy(cmd, path[i]);
			_strcat(cmd, "/");
			_strcat(cmd, str[0]);
			if (execute(cmd, str) == 0)
			{
				shfree(path), shfree(str);
				return (0);
			}
			i++;
		}
	}
	perror("./hsh");
	shfree(path), shfree(str);
	return (1);
}
