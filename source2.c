#include <stdio.h>

#include "source3.h"

extern int a;

int func1()
{
	extern char *str;

	printf("ここは、source2.cのfunc1関数\na = % d\n", a);
	printf("strも見えます---%s\n", str);
	return 0;
}
