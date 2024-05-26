#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char filename[256];
	int c;

	printf("ファイル名(拡張子不要)--");
	fgets(filename, sizeof(filename), stdin);
	filename[strlen(filename) - 1] = '\0';
	fp = fopen(strcat(filename, ".txt"), "r");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。\n");
		return -1;
	}

	while ((c = fgetc(fp)) != EOF) putc(c, stdout);

	return 0;
}
