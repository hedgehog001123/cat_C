#include <stdio.h>

#include "source2.h"

int func2()
{
	extern int a;
	extern char *str;

	printf("ここは、source3.cのfunc2関数です\na = %d\n", a);
	printf("%s\n", str);

	return 0;
}

char *str = "abc";


#include <stdio.h>

void hello(void) {
	printf("Hello, World!");
	return;
}

int main(void)
{
	printf("ここはmain関数");
	hello();
	return;
}
