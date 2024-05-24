#include <stdio.h>
#include <float.h>

int main() {
    double pai = 3.14159265358979;
    int mon = 0;
    float flt = 1.2f;

    printf("%5.2f\n", flt);
    printf("%-5.2f\n", flt);
    printf("%05.2f\n", flt);
    printf("%+08.2f\n", flt);
    printf("%-08.2f\n", flt);

    printf("%d\n", mon = 3);
    printf("%e\n", pai);

    printf("%f\n", pai);
    printf("%010.2f\n", pai);
    printf("%-10.2f\n", pai);
    printf("%10.2f\n", pai);

    return 0;
}
