#include "main.h"
/**
 * non_inter - gets env
 *
 * Description: something
 */
void non_inter(void)
{
	int bytes;
	char buf[1024];
	char **argv;
	char **lines;
	int i = 0;

	bytes = read(STDIN_FILENO, buf, 1023);
	if (bytes == 0)
		return;
	buf[bytes] = '\0';
	lines = line_breaker(buf);

	while (lines[i] != NULL)
	{
		argv = splice(lines[i]);
		if (argv == NULL)
			return;
		path_search(argv);
		i++;
	}
	shfree(lines);
}
