#include "main.h"

/**
 * main - gets env
 * @ac: a var
 * @av: a var
 *
 * Description: something
 * Return: 0
 */

int main(int ac, char **av)
{
	int bytes;
	char buf[100];
	char **argv;

	if (ac == 2)
	{
		file_mode(av[1]);
		return (0);
	}
	if (isatty(0) == 0)
	{
		non_inter();
		return (0);
	}
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		bytes = read(STDIN_FILENO, buf, 99);
		if (bytes == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		buf[bytes] = '\0';
		argv = splice(buf);
		if (argv == NULL)
			continue;
		if (_strcmp(argv[0], "exit") == 0)
			exitf(argv, NULL);
		else if (_strcmp(argv[0], "env") == 0)
			shfree(argv), envprint();
		else
			path_search(argv);
	}
	return (0);
}
