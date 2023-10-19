#include "main.h"
/**
 * non_inter - gets env
 *
 * Description: something
 */
void non_inter(void)
{
	int bytes;
	char buf[6144];
	char **argv;
	char **lines;
	int i = 0;

	bytes = read(STDIN_FILENO, buf, 6143);
	if (bytes == 0)
		return;
	buf[bytes] = '\0';
	lines = line_breaker(buf);

	while (lines[i] != NULL)
	{
		argv = splice(lines[i]);
		if (argv == NULL)
		{
			i++;
			continue;
		}
		path_search(argv);
		i++;
	}
	shfree(lines);
}
