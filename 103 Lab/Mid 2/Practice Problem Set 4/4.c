#include<stdio.h>
int main()
{
    int n, i, count1 = 0, count2 = 0;
    printf("Array Size: ");
    scanf("%d", &n);
    printf("Input Array: ");
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
    {
        if(a[i] > 0)
            count1++;
        else if(a[i] < 0)
            count2++;
    }

    if(count1 > count2)
        printf("Major Positive");
    else if(count2 > count1)
        printf("Major Negative");
    else
        printf("Neutral");
}
