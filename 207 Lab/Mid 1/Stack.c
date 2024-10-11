#include<stdio.h>
#include<stdlib.h>

int top = -1;
int stack[100];

void push(int x, int size)
{
	if(top == size - 1)
        printf("The stack is full\n");
	else
	{
		top++;
		stack[top] = x;
	}
}

void pop()
{
	if(top == -1)
        printf("The stack is empty\n");
	else
    {
        printf("The popped element is %d\n", stack[top]);
		top--;
    }
}

int peek()
{
    if(top == -1)
        printf("The stack is empty\n");
    else
        printf("%d ", stack[top]);
}

void print()
{
    if(top == -1)
        printf("The stack is empty\n");
	for(int i = top; i >= 0; i--)
		printf("%d ", stack[i]);
}


int main()
{
    int choice, n, x;
    printf("Enter the size: ");
    scanf("%d", &n);
    while(1){
        printf("1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n");
        printf("\nEnter your choice(1-5): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x, n);
                printf("\n");
                break;
            }
            case 2:
            {
                pop();
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
                print();
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
