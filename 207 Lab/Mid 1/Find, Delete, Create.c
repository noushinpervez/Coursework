#include<stdio.h>
#include<stdlib.h>

struct Node
{
    float data;
    struct Node *next;
};

struct Node *head, *tail = NULL;

void insert(float data)
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
        printf("%.2f ", list->data);
        list = list->next;
    }
    printf("\n");
}

void search(float x)
{
    struct Node* curr = head;
    int flag = 0;
    if(head == NULL)
        printf("List is empty");

    while(curr != NULL)
    {
        if(curr->data == x)
        {
            return 1;
            break;
        }
        curr = curr->next;
    }
    if(flag == 1)
        printf("%.2f is present in the list\n", x);
    else
        printf("%.2f is not present in the list!!\n", x);
}

void del(struct Node **head, float val)
{
    search(val);
    struct Node *tmp;
    if((*head)->data == val)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }
    struct Node *curr = *head;
    while(curr->next != NULL)
    {
        if(curr->next->data == val)
        {
            tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
            break;
        }
        curr = curr->next;
    }
}

int main()
{
    int choice;
    float x, element;
    while(1){
        printf("1. Find an element\n2. Delete an element\n3. Print the list\n4. Exit\n0. Create a list\n");
        printf("\nEnter your choice(0-4): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
            {
                printf("Enter element to create a list: ");
                scanf("%f", &element);
                insert(element);
                printf("\n");
                break;
            }
            case 1:
            {
                printf("Enter the element to find: ");
                scanf("%f", &x);
                search(x);
                printf("\n");
                break;
            }
            case 2:
            {
                printf("Enter the element to delete: ");
                scanf("%f", &x);
                del(&head, x);
                printf("\n");
                break;
            }
            case 3:
            {
                printList(head);
                printf("\n");
                break;
            }
            case 4:
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

