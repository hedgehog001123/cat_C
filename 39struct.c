#include <stdio.h>
#include <string.h>

struct Man {
	char name[32];
	int age;
};

int main(void)
{
	struct Man student;

	strcpy(student.name, "山田");
	student.age = 15;

	printf("%s %d\n", student.name, student.age);

	return 0;
}
