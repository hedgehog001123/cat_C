#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1) {
		printf("コマンドライン引数がない/n");
		return -1;
	}
	for (i = 0; i < argc; i++) {
		printf("argv[%d]は%sです。", i, argv[i]);
	}

	return 0;
}
