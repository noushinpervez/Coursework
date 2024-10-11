#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1;
int queue[100];

void enqueue(int x, int size)
{
	if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else if((rear + 1) % size == front)
        printf("Queue is full\n");
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = x;
    }
}

void dequeue(int size)
{
    if((front == -1) && (rear == -1))
        printf("Queue is empty\n");
    else if(front == rear)
    {
        printf("The dequeued element is %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("The dequeued element is %d\n", queue[front]);
        front = (front + 1) % size;
    }
}

int peek()
{
    if(front == -1 && rear == -1)
        printf("Queue is empty\n");
    else
        printf("%d \n", queue[front]);
}

void print(int size)
{
    if((front == -1) && (rear = -1))
        printf("Queue is empty\n");
    if (rear >= front)
    {
        for(int i = front; i <= rear; i++)
            printf("%d ",queue[i]);
    }
    else
    {
        for(int i = front; i < size; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}


int main()
{
    int choice, n, x;
    printf("Enter the size: ");
    scanf("%d", &n);
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Print\n5. Exit\n");
        printf("\nEnter your choice(1-5): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x, n);
                printf("\n");
                break;
            }
            case 2:
            {
                dequeue(n);
                printf("\n");
                break;
            }
            case 3:
            {
                peek();
                printf("\n");
                break;
            }
            case 4:
            {
                print(n);
                printf("\n");
                break;
            }
            case 5:
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
