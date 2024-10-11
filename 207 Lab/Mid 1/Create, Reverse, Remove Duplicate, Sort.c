#include<stdio.h>
#include<stdlib.h>

struct Node
{
    double data;
    struct Node *next;
};

struct Node *head, *tail = NULL;

void reverse(struct Node **head)
{
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void sort()
{
    struct Node *curr = head, *i = NULL;
    double tmp;
    if(head == NULL)
        return;
    else
    {
        while(curr != NULL)
        {
            i = curr->next;
            while(i != NULL)
            {
                if(curr->data > i->data)
                    {
                        tmp = curr->data;
                        curr->data = i->data;
                        i->data = tmp;
                    }
                    i = i->next;
            }
            curr = curr->next;
        }
    }
}

void duplicate_del()
{
    struct Node *curr = head, *i = NULL, *tmp = NULL;
    if(head == NULL)
        return;
    else
    {
        while(curr != NULL)
        {
            tmp = curr;
            i = curr->next;
            while(i != NULL)
            {
                if(curr->data == i->data)
                    tmp->next = i->next;
                else
                    tmp = i;

                i = i->next;
            }
            curr = curr->next;
        }
    }
}

void insert(double data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void printList(struct Node *list)
{
    while(list != NULL)
    {
        printf("%.2lf ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    double element;
    while(1){
        printf("1. Create a list\n2. Reverse the list\n3. Remove duplicate\n4. Sort the list\n5. Print the list\n6. Exit\n");
        printf("\nEnter your choice(1-6): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter an element to create a list: ");
                scanf("%lf", &element);
                insert(element);
                printf("\n");
                break;
            }
            case 2:
            {
                reverse(&head);
                printf("\n");
                break;
            }
            case 3:
            {
                duplicate_del();
                printf("\n");
                break;
            }
            case 4:
            {
                sort();
                printf("\n");
                break;
            }
            case 5:
            {
                printList(head);
                printf("\n");
                break;
            }
            case 6:
            {
                return 0;
            }
            default:
            {
                printf("Invalid Input!!\n\n");
                break;
            }
        }
    }
}
