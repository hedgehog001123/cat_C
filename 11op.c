#include <stdio.h>

int main(void)
{
	double height = 1.56, weight = 62.8;

	printf("BMI = weight / (height)^2\n");
	printf("身長%4.2f,体重%4.2fkgの人は、\n", height, weight);
	printf("BMI = %4.2f ÷ (%4.2f * %4.2f) = %4.2f\n", weight, height, height, weight / (height * height));

	return 0;
}
