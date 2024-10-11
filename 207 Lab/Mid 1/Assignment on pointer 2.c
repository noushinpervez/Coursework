#include<stdio.h>
#include<stdlib.h>

struct std
{
    char name[20];
    char id[20];
    float cgpa;
};

void sort(struct std *p, int size)
{
    printf("\nSorted student information by cgpa in descending order:\n");
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(p[j].cgpa < p[j + 1].cgpa)
            {
                struct std temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
            }
        }
    }
    for(int i = 0; i < size; i++)
        printf("%s\t%s\t%.2f\n", (p + i)->name, (p + i)->id, (p + i)->cgpa);
}

void del(struct std *p, int size, char key[20])
{
    int index = 0;
    printf("\nOutput after deleting an element:\n");
    for(int i = 0; i < size; i++)
    {
        if(strcmp(key, p[i].id) == 0)
            index = i;
    }
    for(int i = 0; i < index; i++)
        printf("%s\t%s\t%.2f\n", (p + i)->name, (p + i)->id, (p + i)->cgpa);
    for(int i = index; i < size - 1; i++)
    {
        int j = i + 1;
        printf("%s\t%s\t%.2f\n", (p + j)->name, (p + j)->id, (p + j)->cgpa);
    }
}

void max(struct std *p, int size)
{
    float max = (p + 0)->cgpa;
    int index = 0;
    for(int i = 1; i < size; i++)
    {
        if((p + i)->cgpa > max)
        {
            index = i;
            max = (p + i)->cgpa;
        }
    }
    printf("\nHighest cgpa and student information:\n");
    for(int i = 0; i < size; i++)
    {
        if(index == i)
            printf("%s\t%s\t%.2f\n", (p + i)->name, (p + i)->id, max);
    }
}

int main(){
    struct std *p;
    int size;
    p = (struct std *)malloc(size * sizeof(struct std));
    printf("Enter the size: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++)
    {
        printf("Enter student name: ");
        scanf("%s", (p + i)->name);
        printf("Enter student id: ");
        scanf("%s", (p + i)->id);
        printf("Enter student cgpa: ");
        scanf("%f", &(p + i)->cgpa);
    }
    printf("\nOutput:\n");
    for(int i = 0; i < size; i++)
        printf("%s\t%s\t%.2f\n", (p + i)->name, (p + i)->id, (p + i)->cgpa);

    max(p, size);
    char key[20];
    printf("\nEnter the student id to delete: ");
    scanf("%s", &key);
    del(p, size, key);
    sort(p, size);
    return 0;
}

