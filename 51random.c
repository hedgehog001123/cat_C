#define FNAME "51meibo.txt"
#define RECORDLEN 87

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
int myread();
int mywrite();
int myrewrite();

char * format = "%-15s %-3d %-2s %-63s\n";

int main()
{
	int menuno;

	while(1) {
		menuno = menu();
		switch (menuno) {
			case 0:
				break;
			case 1:
				mywrite();
				break;
			case 2:
				myread();
				break;
			case 3:
				myrewrite();
				break;
			default:
				printf("不正です\n");
				break;
		}
		if (!menuno) break;
	}

	return 0;
}

int menu()
{
	char ret[8];

	while (1) {
		printf("******************\n");
		printf("1: データ書き込み(新規・追加)\n");
		printf("2: データ読みだし\n");
		printf("3: データ修正\n");
		printf("0: 終了\n");
		printf("******************\n");
		printf("選択--> ");
		fgets(ret, sizeof(ret), stdin);
		ret[1] = '\0';
		if (ret[0] < '0' || ret[0] > '3') {
			printf("番号が不正です。\n");
			continue;
		}
		return atoi(ret);
	}
}

int mywrite()
{
	FILE *fp;
	char name[16], sex[4], address[64], buffer[8];
	int age;

	fp = fopen(FNAME, "a");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。\n");
		return -1;
	}
	while (1) {
		printf("氏名--");
		fgets(name, sizeof(name), stdin);
		name[strlen(name) - 1] = '\0';
		printf("年齢--");
		fgets(buffer, sizeof(buffer), stdin);
		age = atoi(buffer);
		printf("性別[M/F]--");
		fgets(sex, sizeof(sex), stdin);
		sex[strlen(sex) - 1] = '\0';
		printf("住所--");
		fgets(address, sizeof(address), stdin);
		address[strlen(address) - 1] = '\0';

		if (fprintf(fp, format, name, age, sex, address) < 0) {
			perror("書き込みエラーが発生しました。\n");
			return -1;
		}
		printf("さらに入力を続けますか[Y/N]");
		fgets(buffer, sizeof(buffer), stdin);
		if (buffer[0] == 'n' || buffer[0] == 'N') break;
	}

	fclose(fp);
	return 0;
}

int myread()
{
	FILE *fp;
	char search[16], yesno[8], name[16], sex[4], address[64];
	int no = 0, find = 0, age;

	fp = fopen(FNAME, "r");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。");
		return -1;
	}

	printf("検索する氏名--");
	fgets(search, sizeof(search), stdin);
	search[strlen(search) - 1] = '\0';

	while (1) {
		fseek(fp, RECORDLEN * no++, SEEK_SET);
		if (fscanf(fp, "%s", name) == EOF) break;
		if (strstr(name, search) != NULL) {
			find++;
			fscanf(fp, "%d", &age);
			fscanf(fp, "%s", sex);
			fscanf(fp, "%s", address);
			printf("氏名: %s\n", name);
			printf("年齢: %d\n", age);
			printf("性別: %s\n", sex);
			printf("住所: %s\n", address);
			printf("--------------\n");
			printf("さらに続けますか[Y/N]:");
			fgets(yesno, sizeof(yesno), stdin);
			if (yesno[0] == 'y' || yesno[0] == 'Y') continue;
			else break;
		}
	}
	printf("%d 件が検索されました\n", find);
	fclose(fp);
	return 0;
}

int myrewrite()
{
	FILE *fp;
	char buffer[8], shusei[16], yesno[8], name[16], sex[4], address[64];
	int no = 0, age, find = 0;

	fp = fopen(FNAME, "r+");
	if (fp == NULL) {
		perror("ファイルをオープンできませんでした。\n");
		return -1;
	}
	printf("修正するデータの氏名--");
	fgets(shusei, sizeof(shusei), stdin);
	shusei[strlen(shusei) - 1] = '\0';

	while (1) {
		fseek(fp, RECORDLEN * no++, SEEK_SET);
		if (fscanf(fp, "%s", name) == EOF) break;
		if (strstr(name, shusei) != NULL) {
			find = 1;
			fscanf(fp, "%d", &age);
			fscanf(fp, "%s", sex);
			fscanf(fp, "%s", address);
			printf("氏名: %s\n", name);
			printf("年齢: %d\n", age);
			printf("性別: %s\n", sex);
			printf("住所: %s\n", address);
			printf("---------------\n");
			printf("このデータを修正しますか[Y/N]:");
			fgets(yesno, sizeof(yesno), stdin);
			if (yesno[0] == 'y' || yesno[0] == 'Y') {
				printf("氏名を修正しますか[Y/N]");
				fgets(yesno, sizeof(yesno) - 1, stdin);
				if (yesno[0] == 'y' || yesno[0] == 'Y') {
					printf("--氏名");
					fgets(name, sizeof(name), stdin);
					name[strlen(name) - 1] = '\0';
				}
				printf("年齢を修正しますか[Y/N]");
				fgets(yesno, sizeof(yesno), stdin);
				if (yesno[0] == 'y' || yesno[0] == 'Y') {
					printf("--年齢");
					fgets(buffer, sizeof(buffer), stdin);
					age = atoi(buffer);
				}
				printf("性別を修正しますか[Y/N]");
				fgets(yesno, sizeof(yesno), stdin);
				if (yesno[0] == 'y' || yesno[0] == 'Y') {
					printf("--性別");
					fgets(sex, sizeof(sex), stdin);
					sex[strlen(sex) - 1] = '\0';
				}
				printf("住所を修正しますか[Y/N]");
				fgets(yesno, sizeof(yesno), stdin);
				if (yesno[0] == 'y' || yesno[0] == 'Y') {
					printf("--住所");
					fgets(address, sizeof(address), stdin);
					address[strlen(address) - 1] = '\0';
				}
				fseek(fp, RECORDLEN * (no - 1), SEEK_SET);
				fprintf(fp, format, name, age, sex, address);
			}
		}
	}
	if (find == 0) printf("修正すべきデータはありませんでした\n");

	fclose(fp);
	return 0;
}


