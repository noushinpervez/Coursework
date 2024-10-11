#include<stdio.h>

int main() {

    int *p; //I am declaring a variable called p which is pointer to an int
    int a = 10; //I am declaring an integer variable called a


    p = &a; // I am assigning the memory address of a to the pointer variable, p. p is now pointing to the address of a

    printf("a = %d\n", a);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p); // *p is used to get the value of a

    // *p can also be used to set the value of a
    *p = 100;
    printf("a = %d\n", a);

    return 0;
}
