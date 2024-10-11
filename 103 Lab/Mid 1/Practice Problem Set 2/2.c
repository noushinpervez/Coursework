#include<stdio.h>
int main()
{
    int salary, tax;
    printf("Enter salary: ");
    scanf("%d", &salary);

    if(salary < 30000)
        tax = salary * 0.4;
    else if(salary >= 30000 && salary <= 70000)
        tax = salary * 0.1;
    else if(salary > 70000)
        tax = salary * 0.15;

    printf("%d", tax);
}
