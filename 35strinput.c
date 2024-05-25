#include <stdio.h>
#include <string.h>

int main()
{
	char str[64];

	printf("文字列を入力してください--");
	fgets(str, sizeof(str), stdin);
	str[strlen(str)-1] = '\0';

	printf("入力した文字列は「%s」です\n", str);

	return 0;
}
