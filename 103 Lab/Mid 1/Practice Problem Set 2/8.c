#include<stdio.h>
int main()
{
    int i1, i2, i3, i4, large1, small1, large2, small2, largest, smallest;
    printf("Enter the integers: ");
    scanf("%d%d%d%d", &i1, &i2, &i3, &i4);

    if(i1 < i2){
        small1 = i1;
        large1 = i2;
    }else{
        small1 = i2;
        large1 = i1;
    }if(i3 < i4){
        small2 = i3;
        large2 = i4;
    }else{
        small2 = i4;
        large2 = i3;
    }

    if(large1 < large2)
        largest = large2;
    else
        largest = large1;
    if(small1 < small2)
        smallest = small1;
    else
        smallest = small2;

    printf("Largest = %d\n", largest);
    printf("Smallest = %d", smallest);
}
