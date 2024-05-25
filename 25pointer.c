#include <stdio.h>

int main(void)
{
	int *pa;
	int a;
	pa = &a;
	*pa = 5;

	printf("*pa = %d\n", *pa);
	printf("a = %d\n", a);

	return 0;
}
