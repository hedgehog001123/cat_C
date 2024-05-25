#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[32], str2[32];
	int cmp;

	printf("str1を入力してください--");
	scanf("%s", str1);
	printf("str2を入力してください--");
	scanf("%s", str2);

	cmp = strcmp(str1, str2);
	if (cmp < 0) printf("%sは、%sよりも前にある\n", str1, str2);
	else if (cmp == 0) printf("%sと%sは同じ文字列\n", str1, str2);
	else printf("%sは、%sより後にある。\n", str1, str2);

	return 0;
}
