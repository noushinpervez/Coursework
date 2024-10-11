#include<stdio.h>
#include<stdlib.h>

struct std
{
    char name[30];
    char address;
    double NID;
    float amount;
};

int main(){
    struct std *p;
    int size = 2;
    p = (struct std *)malloc(size * sizeof(struct std));
    for(int i = 0; i < size; i++)
    {
        printf("Enter student name,address, NID, and amount: ");
        scanf("%s %s %d %f", (p + i)->name,(p + i)->address, &(p + i)->NID, &(p + i)->amount);
    }
    printf("Output: ");
    for(int i = 0; i < size; i++)
        printf("%s %s %d %f\n", (p + i)->name,(p + i)->address, (p + i)->NID, (p + i)->amount);


}
