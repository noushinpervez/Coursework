#include<stdio.h>

int recSearch(int a[], int first, int last, int key)
{
    if(first <= last)
    {
        int mid = first + (last - first) / 2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return recSearch(a, first, mid - 1, key);
        else
            return recSearch(a, mid + 1, last, key);
    }
    return -1;
}

int main()
{
    int n, x, ele, a[20];
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    x = recSearch(a, 0, n - 1, ele);
    if(x != -1)
        printf("%d", x);
    else
        printf("Element not found");
}
