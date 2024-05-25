#include <stdio.h>

union MyUnion {
	int i;
	double d;
	char c;
	char *str;
};

int main()
{
	union MyUnion u;

	u.i = 200;
	printf("u.i = %d\n", u.i);
	u.d = 95.25;
	printf("u.d = %f\n", u.d);
	u.c = 'A';
	printf("u.c = %c\n", u.c);
	u.str = "ABCDE";
	printf("u.str = %s\n", u.str);

	return 0;
}
