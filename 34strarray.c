#include <stdio.h>

int main(void)
{
	char str[] = "ABC";

	printf ("%s\n", str);

	str[0] = 'd';
	str[1] = 'e';
	str[2] = 'f';

	printf("%s\n", str);

	return 0;
}
