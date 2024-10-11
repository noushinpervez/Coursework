#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next, *prev;
};

void data_delete (struct node *test, struct node *pretest, int val)
{
    struct node *t1 = test, *prev;
    if(test == NULL)
        return;

    if(test->value == val)
    {
        test = t1->next;
        free(t1);
        return;
    }

    while(t1 != NULL && t1->value != val)
    {
        prev = t1;
        t1 = t1->next;
    }
    if(t1 == NULL)
        return;

    prev->next = t1->next;
    free(t1);
}

void insert(struct node *test, struct node *test1, int x)
{
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->value = x;
    Node->next = NULL;
    Node->prev = NULL;
    if (test->next == NULL)
    {
        test->next = Node;
        test1->prev = Node;
    }
    else
    {
        while(test->next!=NULL)
            test = test->next;

        test->next= Node;
        Node->prev = test;
        test1->prev = Node;
    }
}

void display (struct node *test1, struct node *test2)
{
    struct node *test, *pretest;
    test = test1->next;
    pretest = test2->prev;
    printf("\n");
    while (test != NULL)
    {
        printf(" %d ", test->value);
        test = test->next;
    }
    printf("\n");
    while(pretest != NULL)
    {
        printf(" %d ", pretest->value);
        pretest = pretest->prev;
    }
}

int main(void)
{
    struct node *head, *trail;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    trail = (struct node *)malloc(sizeof(struct node));
    trail->next = NULL;
    insert(head, trail, 5);
    insert(head, trail, 9);
    insert(head, trail, 17);
    insert(head, trail, 12);
    insert(head, trail, 15);
    insert(head, trail, 19);
    display(head, trail);
    data_delete(head, trail, 12);
    display(head, trail);
}
