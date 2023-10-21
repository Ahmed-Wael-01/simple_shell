#include "main.h"

/**
 * file_mode - handles files
 * @name: a var
 *
 * Description: it does something
 * Return: 0
 */

void file_mode(char *name)
{
	int fd, i, bytes;
	char **argv, **lines;
	char buf[6144];

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "./hsh: 0: Can't open ", 22);
		write(2, name, 40);
		write(2, "\n", 1):
		exit(127);
	}
	bytes = read(fd, buf, 6143);
	close(fd);
	if (bytes == 0)
		return;
	buf[bytes] = '\0';
	lines = line_breaker(buf);
	for (i = 0; lines[i] != NULL; i++)
	{
		argv = splice(lines[i]);
		if (argv == NULL)
			continue;
		if (_strcmp(argv[0], "exit") == 0)
			exitf(argv, lines);
		else if (_strcmp(argv[0], "env") == 0)
			shfree(argv), envprint();
		else
			path_search(argv);
	}
	shfree(lines);
}
