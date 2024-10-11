#include<stdio.h>
int main()
{
    int m1, m2, d1, d2, y1, y2;
    printf("Enter first date (day-month-year): ");
    scanf("%d%d%d", &d1, &m1, &y1);
    printf("Enter second date (day-month-year): ");
    scanf("%d%d%d", &d2, &m2, &y2);

    if(y1 == y2){
        if(m1 == m2){
            if(d1 > d2)
                printf("%d/%d%/%.2d is earlier than %d/%d/%.2d\n", d2, m2, y2, d1, m1, y1);
            else
                printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d1, m1, y1, d2, m2, y2);
        }
        else if(m1 > m2)
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d2, m2, y2, d1, m1, y1);
        else
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d1, m1, y1, d2, m2, y2);
    }
    else if(y1 > y2)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d2, m2, y2, d1, m1, y1);
    else
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d1, m1, y1, d2, m2, y2);
}
