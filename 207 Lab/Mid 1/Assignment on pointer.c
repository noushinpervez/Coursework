#include<stdio.h>

void sort(int n, int *ptr)
{
    int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(*(ptr + j) < *(ptr + i))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
    printf("\nSorted elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", *(ptr + i));
}

void del(int n, int *ptr)
{
    int j = 0;
    printf("\nDeleting negative elements: ");
    for(int i = 0; i < n; i++)
    {
        if(*(ptr + i) >= 0)
        {
            *(ptr + j) = *(ptr + i);
            j++;
        }
    }
    for(int i = 0; i < j; i++)
        printf("%d ", *(ptr + i));
}
int main()
{
    int *p;
    int size = 9, max = -999999;
    p = (int*) malloc(size*sizeof(int));
    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++)
    {
        printf("Enter a number: ");
        scanf("%d", p + i);
    }
    printf("\nOutput: ");
    for(int i = 0; i < size; i++)
        printf("%d ", *(p + i));

    for(int i = 0; i < size; i++)
    {
        if(max < *(p + i))
            max = *(p + i);
    }
    printf("\nLargest element: %d", max);
    sort(size, p);
    del(size, p);
}
