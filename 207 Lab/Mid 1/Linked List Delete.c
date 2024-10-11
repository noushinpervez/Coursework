#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void printList(struct Node* list)
{
    while(list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
}

void del(struct Node** head, int val)
{
    struct Node* tmp;
    if((*head)->data == val)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    struct Node* curr = *head;
    while(curr->next != NULL)
    {
        if(curr->next->data == val)
        {
            tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
            break;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));

    head = node1;
    node1->data = 10;
    node1->next = node2;
    node2->data = 5;
    node2->next = node3;
    node3->data = 1;
    node3->next = node4;
    node4->data = 0;
    node4->next = NULL;

    del(&head, -1);
    printList(head);

    return 0;
}
