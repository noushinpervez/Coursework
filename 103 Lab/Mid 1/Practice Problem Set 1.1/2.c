#include<stdio.h>
#include<math.h>
#define PI 3.1415

int main()
{
    int x, r1;
    double r2, val, r3;
    printf("Enter x: ");
    scanf("%d", &x);

    r1 = pow(x, 6);

    val = PI/180.0;
    r2 = cos(x*val);

    r3 = sqrt(x);

    printf("%d\n", r1);
    printf("%.10f\n", r2);
    printf("%.4f", r3);
}
