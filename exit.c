#include "main.h"

/**
 * exitf - exits
 * @str: a var
 * @path: a var
 *
 * Description: it does smthing
 */

void exitf(char **str, char **lines)
{
	int num;

	if (str[1] == NULL)
	{
		shfree(lines);
		shfree(str);
		exit(0);
	}
	num = _atoi(str[1]);
	if (num >= 0)
	{
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
