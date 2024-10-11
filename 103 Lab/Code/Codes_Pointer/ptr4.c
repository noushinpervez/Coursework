#include<stdio.h>

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

void swap2(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(a, b); // call by value
    printf("After swap: a = %d, b = %d\n\n", a, b);

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap2(&a, &b); // call by reference
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
