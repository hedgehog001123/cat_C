#include <stdio.h>

#include "source2.h"
#include "source3.h"

int func1();
int func2();

int a = 100;

int main()
{
	extern char *str;

	printf("ここはmain関数です\na = %d\n", a);
	printf("*strも見えます---%s\n", str);
	func1();
	func2();

	return 0;
}
