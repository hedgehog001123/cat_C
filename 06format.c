#include <stdio.h>

int main() {
    double a = 0.5, b = 10.5;
    int c = 215, d;
    char e = 'A';

    printf("%f + %f = %f\n", a, b, a + b);
    d = c + 11;
    printf("%d + 11 = %d\n", c, d);
    printf("e = %c\n", e);

    return 0;
}
