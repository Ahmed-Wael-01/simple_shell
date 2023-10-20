#include "main.h"

/**
 * exitf - exits
 * @str: a var
 * @lines: a var
 *
 * Description: it does smthing
 */

void exitf(char **str, char **lines)
{
	int num = 0;

	if (str[1] == NULL)
	{
		if (lines == NULL)
			shfree(str), exit(num);
		if (lines[1] != NULL)
			num = 2;
		if (lines != NULL)
			shfree(lines);
		shfree(str);
		exit(num);
	}
	num = _atoi(str[1]);
	if (num >= 0)
	{
		if (lines != NULL)
			shfree(lines);
		shfree(str);
		exit(num);
	}
	else
	{
		shfree(str);
		perror("./hsh");
	}
}
