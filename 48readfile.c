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
	strcat(filename, ".txt");
	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。\n");
		return -1;
	}

	while (fscanf(fp, "%c", &c) != EOF) {
		printf("%c", c);
	}
	fclose(fp);

	return 0;
}
