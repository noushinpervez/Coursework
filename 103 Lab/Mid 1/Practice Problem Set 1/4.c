#include<stdio.h>
int main()
{
    int hour, salary, id, value;
    printf("Enter the information : ");
    scanf("%d%d%d", &id, &value, &hour);
    salary = value * hour;
    printf("Employee %d receives $%d", id, salary);
}
