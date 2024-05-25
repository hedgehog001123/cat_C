#include <stdio.h>

int main(void)
{
	int a;
	double b;
	int c;
	a = 10;
	b = 2.35;
	c = b;

	printf("%d + %f = %f\n", a, b, a + b);
	printf("c = %d\n", c);

	return 0;
}
