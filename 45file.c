#include <stdio.h>

int main()
{
	FILE *fp;

	fp = fopen("45test.txt", "w");

	if (fp == NULL) {
		perror("ファイル・オープンに失敗しました。\n");
		return -1;
	} else {
		printf("ファイルを正常にオープンしました。\n");
	}

	fprintf(fp, "初めてのファイル入出力です。\n");

	if (fclose(fp) != 0) {
		perror("ファイルのクローズに失敗しました。\n");
		return -1;
	} else {
		printf("ファイルを正常にクローズしました。\n");
	}

	return 0;
}
