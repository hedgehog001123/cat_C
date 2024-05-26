#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char filename[256], name[16], tel[16];
	char *format = "%-15s %-15s\n";

	printf("ファイル名(拡張子不要)--");
	fgets(filename, sizeof(filename), stdin);
	filename[strlen(filename) - 1] = '\0';
	strcat(filename, ".txt");
	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。\n");
		return -1;
	}

	while (fscanf(fp, "%s %s", name, tel) != EOF) {
		printf(format, name, tel);
	}

	fclose(fp);
	return 0;
}
