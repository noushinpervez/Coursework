#include<stdio.h>

int iterative(int a, int b)
{
    while(a != 0 && b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a + b;
}

int recursive(int a, int b)
{
    if(a == 0 || b == 0)
        return a + b;
    return recursive(b, a % b);
}

int main()
{
    int n1, n2;
    printf("Enter two numbers to calculate GCD: ");
    scanf("%d %d", &n1, &n2);
    printf("Iterative result: %d\n", iterative(n1, n2));
    printf("Recursive result: %d", recursive(n1, n2));
}
