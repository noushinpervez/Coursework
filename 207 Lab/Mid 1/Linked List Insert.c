#include<stdio.h>
#include<stdlib.h>

struct Node
{
    float data;
    struct Node *next;
};

struct Node *head = NULL;

void printList(struct Node *list)
{
    while(list != NULL)
    {
        printf("%.2f ", list->data);
        list = list->next;
    }
    printf("\n");
}

void insertFirst(struct Node **head, float val)
{
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->data = val;
    first->next = *head;
    *head = first;
}

void insertLast(struct Node **head, float val)
{
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    last->data = val;
    last->next = NULL;
    if(head == NULL)
        *head = last;
    else
    {
        struct Node *end = *head;
        while(end->next != NULL)
            end = end->next;

    end->next = last;
    }
}

void insert(float val, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(position < 1)
        printf("\nInvalid position!!\n");
    else if(position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        for(int i = 1; i < position - 1; i++)
        {
            if(temp != NULL)
                temp = temp->next;
        }
        if(temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
            printf("Invalid position!!\n");
    }
}

int main()
{
    int choice, n;
    float x;
    while(1){
        printf("1. Insert at the first\n2. Insert at the last\n3. Insert at any location\n4. Print\n5. Exit\n");
        printf("\nEnter your choice(1-5): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:{
                printf("Enter the element to insert at the beginning: ");
                scanf("%f", &x);
                insertFirst(&head, x);
                printf("\n");
                break;
            }
            case 2:{
                printf("Enter the element to insert at the end: ");
                scanf("%f", &x);
                insertLast(&head, x);
                printf("\n");
                break;
            }
            case 3:{
                printf("Enter the element to insert at the specified position: ");
                scanf("%f", &x);
                printf("Enter the position(from 1): ");
                scanf("%d", &n);
                insert(x, n);
                printf("\n");
                break;
            }
            case 4:{
                printList(head);
                printf("\n");
                break;
            }
            case 5:{
                return 0;
            }
            default:{
                printf("Invalid Input!!\n\n");
                break;
            }
        }
    }
}
