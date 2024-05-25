#define CAT		1
#define DOG		2
#define RAT		4
#define RABBIT	8

#include <stdio.h>

int main(void)
{
	int a = CAT | DOG;
	int b = RAT;
	int c = CAT | DOG | RAT | RABBIT;
	int d = DOG | RAT;

	printf("A...猫%d, 犬%d, 鼠%d, 兎%d\n", (a & CAT), (a & DOG), (a & RAT), (a & RABBIT));
	printf("A...猫%d, 犬%d, 鼠%d, 兎%d\n", (b & CAT), (b & DOG), (b & RAT), (b & RABBIT));
	printf("A...猫%d, 犬%d, 鼠%d, 兎%d\n", (c & CAT), (c & DOG), (c & RAT), (c & RABBIT));
	printf("A...猫%d, 犬%d, 鼠%d, 兎%d\n", (d & CAT), (d & DOG), (d & RAT), (d & RABBIT));

	return 0;
}

