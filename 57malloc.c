#include <stdio.h>
#include <malloc.h>

int main()
{
	int *pi;

	pi = (int *)malloc(sizeof(int));

	if (pi == NULL) {
		perror("メモリの確保に失敗しました\n");
		return -1;
	}

	* pi = 100;
	printf("*pi = %d\n", *pi);

	free(pi);

	return 0;
}
