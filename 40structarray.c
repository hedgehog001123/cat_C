#define STUDENTNO 5
#define SUBJECTNO 3

#include <stdio.h>

int drawline(void);

struct Seiseki {
	char name[32];
	int kokugo;
	int sugaku;
	int eigo;
};

int main(void)
{
	struct Seiseki myclass[STUDENTNO] = {
		{"田中", 80, 80, 55 },
		{"田中B", 52, 61, 11 },
		{"中田", 22, 63, 44 },
		{"田井中", 70, 24, 77 },
		{"ゴリラ", 80, 90, 55 },
	};
	int i, sum0 = 0, sum1[SUBJECTNO], sum2[STUDENTNO];

	for (i = 0; i < SUBJECTNO; i++) sum1[i] = 0;
	for (i = 0; i < STUDENTNO; i++) sum2[i] = 0;

	for (i = 0; i < STUDENTNO; i++) {
		sum1[0] += myclass[i].kokugo;
		sum1[1] += myclass[i].sugaku;
		sum1[2] += myclass[i].eigo;
	}

	for (i = 0; i < STUDENTNO; i++) {
		sum2[i] = myclass[i].kokugo + myclass[i].sugaku + myclass[i].eigo;
	}

	for (i = 0; i < STUDENTNO; i++) sum0 += sum2[i];

	printf("**** 成績 ****\n\n");

	printf("%6s %6s %6s %6s %6s\n","氏名", "国語", "数学", "英語", "合計");
	drawline();

	for (i = 0; i < STUDENTNO; i++) printf("%6s %6d %6d %6d %6d\n", myclass[i].name, myclass[i].kokugo, myclass[i].sugaku, myclass[i].eigo, sum2[i]);

	drawline();
	printf("%6s %6.1f %6.1f %6.1f %6.1f\n",
	"平均",
	(double)sum1[0] / STUDENTNO,
	(double)sum1[1] / STUDENTNO,
	(double)sum1[2] / STUDENTNO,
	(double)sum0 / STUDENTNO);
	return 0;
}

int drawline(void)
{
	int i;

	for (i = 0; i < 35; i++) printf("-");
	printf("\n");

	return 0;
}
