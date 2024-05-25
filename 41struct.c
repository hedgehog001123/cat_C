#include <stdio.h>
#include <string.h>

struct Data {
	char name[32];
	int age;
	double bl;
};

int struct_input(struct Data *);

int main(void)
{
	struct Data mydata;
	char format[] = "%s さん(%d歳)\n"
		"身長 = %5.1fcm\n";
	char buffer[256];

	struct_input(&mydata);
	sprintf(buffer, format, mydata.name, mydata.age, mydata.bl);
	printf(buffer);

	return 0;
}

int struct_input(struct Data *p)
{
	char name[32];
	printf("氏名---");

	fgets(name, sizeof(name), stdin);
	if (strchr(name, '\n') != NULL) {
		name[strlen(name) - 1] = '\0';
	} else {
		while(getchar() != '\n');
	}
	strcpy(p->name, name);

	printf("年齢---");
	scanf("%d", &p->age);
	printf("身長cm---");
	scanf("%lf", &p->bl);

	return 0;
}
