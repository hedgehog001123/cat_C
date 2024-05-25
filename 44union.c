#define PAN "パン食い競争"
#define KYO "100m 競争"
#define NO 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[16];
	char kyogi[32];
	union {
		double tm;
		int juni;
	} seiseki;
} MyDataType, *lpMyDataType;

int myinput(lpMyDataType, char *, char *, char *);

int main(void)
{
	MyDataType data[NO];
	lpMyDataType lpdata;
	int i;
	
	lpdata = data;
	myinput(lpdata + 0, "田中", PAN, "1");
	myinput(lpdata + 1, "構築", KYO, "20.5");
	myinput(lpdata + 2, "最後", PAN, "2");
	myinput(lpdata + 3, "群馬", PAN, "4");
	myinput(lpdata + 4, "栃木", KYO, "15.2");
	myinput(lpdata + 5, "波木", PAN, "3");

	printf("%4s %-14s %4s\n", "氏名", "競技名", "成績");
	printf("---------------------\n");
	for (i = 0; i < NO; i++) {
		printf("%4s %-14s ", data[i].name, data[i].kyogi);
		if (strcmp(data[i].kyogi, "100m 競争") == 0){
			printf("%4.1f 秒\n", data[i].seiseki.tm);
		} else {
			printf("%4d 位\n", data[i].seiseki.juni);
		}
	}

	return 0;
}

int myinput(lpMyDataType p, char *nm, char *kg, char *sk)
{
	strcpy(p->name, nm);
	strcpy(p->kyogi, kg);
	if (strcmp(kg, PAN) == 0) p->seiseki.juni = atoi(sk);
	else p->seiseki.tm = atof(sk);
	return 0;
}
