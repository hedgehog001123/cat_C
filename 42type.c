#include <stdio.h>

typedef struct Data {
	char name[32];
	int age;
	struct Data *nextdata;
} MyDataType;

int main(void)
{
	MyDataType a = {"田井中", 28, },
	b = {"鈴木森", 38, },
	c = {"大中林", 95, };

	MyDataType *lpdata;

	a.nextdata = &b;
	b.nextdata = &c;
	c.nextdata = NULL;

	for (lpdata = &a; lpdata; lpdata = lpdata->nextdata) printf("%s (%d歳)\n", lpdata->name, lpdata->age);

	return 0;
}
