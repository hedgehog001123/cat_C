#include <stdio.h>

int main(void)
{
	int a = 10, b = 4;
	double c;

	c = a / b;

	printf("%d ÷ %d = %f\n", a, b, a / b);
	printf("%d ÷ %d = %f\n", a, b, c);
	printf("%d ÷ %d = %f\n", a, b, (double)a / b);

	return 0;
}
