#include "main.h"
/**
 * non_inter - gets env
 *
 * Description: something
 */
void non_inter(void)
{
	char buf[6144];
	char **argv, **lines;
	int i, bytes;

	bytes = read(STDIN_FILENO, buf, 6143);
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
		else
			path_search(argv);
	}
	shfree(lines);
}
