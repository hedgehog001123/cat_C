#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char filename[256];
	unsigned char c;
	int no = 0;

	printf("ファイル名---");
	fgets(filename, sizeof(filename), stdin);
	filename[strlen(filename) - 1] = '\0';
	fp = fopen(filename, "rb");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。\n");
		return -1;
	}
	while(fread(&c, sizeof(char), 1, fp) != 0) {
		printf("%02X ", c);
		no++;
		if (no % 8 == 0) printf("\n");
	}
	printf("\n");
	fclose(fp);
	return 0;
}
