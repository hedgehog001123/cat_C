#include <stdio.h>

int function();

int i = 10;

int main(void)
{
	int i = 5;
	{
		int i = 3;
		printf("i = %d\n", i);
	}

	printf("i = %d\n", i);
	function();

	return 0;
}

int function()
{
	printf("i = %d\n", i);
	return 0;
}
