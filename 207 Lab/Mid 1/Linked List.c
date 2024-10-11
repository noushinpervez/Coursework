#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* list)
{
    while(list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
}

int main()
{
    struct Node* head;
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    head = node1;
    node1->data = 10;
    node1->next = node2;
    node2->data = 5;
    node2->next = node3;
    node3->data = 1;
    node3->next = NULL;

    printList(head);

    return 0;
}
