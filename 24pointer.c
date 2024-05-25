#include <stdio.h>

int main(void)
{
	int a;
	int *lpa;
	lpa = &a;

	printf("整数値を入力: ");
	scanf("%d", &a);
	printf("変数aに%dが入力された\n", a);
	printf("aのアドレスは%p\n", &a);
	printf("aを指しているポインタはlpa\n");
	printf("*lpaの値は%d\n", *lpa);

	return 0;
}
