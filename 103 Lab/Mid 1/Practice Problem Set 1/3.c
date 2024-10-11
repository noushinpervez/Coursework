#include<stdio.h>
int main()
{
    int u, a, t, v, s;
    printf("Enter the value: ");
    scanf("%d%d%d", &u, &a, &t);

    v = u + a * t;
    s = u * t + 0.5 * a * t * t;

    printf("v = %d\n", v);
    printf("s = %d", s);
}
