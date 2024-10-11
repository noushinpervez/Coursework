#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter the string: ");
    gets(s);

    int l = 0, i, j;
    while(s[l] != '\0')
        l++;
    for(i = l - 1; i >= 0; i--)
    {
        for(j = 0; j <= i; j++)
            printf("%c", s[j]);

        printf("\n");
    }
}
