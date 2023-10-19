#include "main.h"

/**
 * exitf - exits
 * @str: a var
 * @path: a var
 *
 * Description: it does smthing
 */

void exitf(char **str, char **path)
{
	int num;

	if (str[1] == NULL)
	{
		shfree(str);
		shfree(path);
		exit(0);
	}
	num = _atoi(str[1]);
	if (num >= 0)
	{
		shfree(str);
		shfree(path);
		exit(num);
	}
}
