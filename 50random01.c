#define RECORDLEN 33
// 名前15 + 空白1 + 電話番号15 + 改行文字2 = 33バイト

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char filename[256], data[16], ans[8];
	int no;

	printf("ファイル名(拡張子不要)--");
	fgets(filename, sizeof(filename) - sizeof(".txt"), stdin);
	filename[strlen(filename) - 1] = '\0';
	fp = fopen(strcat(filename, ".txt"), "r");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。\n");
		return -1;
	}

	while(1) {
		printf("何人目のデータを読み込みますか---");
		fgets(ans, sizeof(ans), stdin);
		no = atoi(ans);
		fseek(fp, RECORDLEN * (no - 1), SEEK_SET);
		if (fscanf(fp, "%s", data) == EOF) {
			perror("読み込みエラーです\n");
			continue;
		}
		printf("[氏名] %s", data);
		fscanf(fp, "%s", data);
		printf("[電話] %s\n", data);
		printf("続けますか[Y/N]: ");

		fgets(ans, sizeof(ans), stdin);
		ans[strlen(ans) - 1] = '\0';
		if (strcmp(ans, "n") == 0 || strcmp(ans, "N") == 0) {
			break;
		}
	}
}
